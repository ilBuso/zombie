#include "game.hpp"

#include "../ECS/components/components.hpp"
#include "../collision/collision.hpp"
#include "../gameobject/gameobject.hpp"
#include "../map/map.hpp"

#include <SDL2/SDL.h>

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;
SDL_Rect Game::camera = {0, 0, 1550, 1550};

Time d_time;

Map* map;
// auto& player(manager->add_entity());

GameObject* player;

Manager* Game::manager = new Manager();

AssetManager* Game::asset_manager = new AssetManager(manager);

bool Game::is_running = false;

// Constructor
Game::Game() {}

// Destroyer
Game::~Game() {}

/// Functions
bool Game::init(void) {

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cerr << "Error Initializing SDL" << std::endl;
        return false;
    }

    // Create window
    window =
        SDL_CreateWindow(NULL, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                         0, 0, SDL_WINDOW_FULLSCREEN_DESKTOP);
    if (!window) {
        std::cerr << "Error creating SDL Window" << std::endl;
        return false;
    }

    // Create renderer
    renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer) {
        std::cerr << "Error creating SDL Renderer" << std::endl;
        return false;
    }

    SDL_GetWindowSize(window, &window_width, &window_height);

    is_running = true;

    return true;
}

void Game::kill() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Game::setup() {
    asset_manager->add_texture("map", "assets/tiles/map.png");
    asset_manager->add_texture("collider", "assets/tiles/collider.png");
    asset_manager->add_texture("player", "assets/animations/player.png");

    map = new Map("map", 2, 32);
    map->load_map("assets/map/map.map", 32, 32);

    player = new GameObject("player", true, Game::players_group);

    player->gameobject.add_component<Time>();
    player->gameobject.add_component<Collider>("player");
    player->gameobject.add_component<KeyboardController>();

    /*player.add_component<Time>();
    player.add_component<Transform>(3);
    player.add_component<Collider>("player");
    player.add_component<Sprite>("player", true);
    player.add_component<KeyboardController>();
    player.add_group(players_group);*/
}

auto& tiles(Game::manager->get_group(Game::map_group));
auto& players(Game::manager->get_group(Game::players_group));
auto& colliders(Game::manager->get_group(Game::colliders_group));

void Game::handle_events() {
    SDL_PollEvent(&event);

    switch (event.type) {
        case SDL_QUIT:
            is_running = false;
            break;
        default:
            break;
    }
}

void Game::update() {

    SDL_Rect player_collider =
        player->gameobject.get_component<Collider>().collider;
    Vector2D player_position =
        player->gameobject.get_component<Transform>().position;

    manager->refresh();
    manager->update();

    for (auto& c : colliders) {
        SDL_Rect c_collider = c->get_component<Collider>().collider;
        if (Collision::AABB(c_collider, player_collider)) {
            player->gameobject.get_component<Transform>().position =
                player_position;
        }
    }

    Transform player_transform = player->gameobject.get_component<Transform>();

    camera.x = (player_transform.position.x +
                ((player_transform.width * player_transform.scale) / 2.0f)) -
               (window_width / 2.0f);
    camera.y = (player_transform.position.y +
                ((player_transform.width * player_transform.scale) / 2.0f)) -
               (window_height / 2.0f);

    if (camera.x < 0) {
        camera.x = 0;
    }
    if (camera.y < 0) {
        camera.y = 0;
    }
    if (camera.x > camera.w) {
        camera.x = camera.w;
    }
    if (camera.y > camera.h) {
        camera.y = camera.h;
    }
}

void Game::render() {
    SDL_RenderClear(renderer);

    for (auto& t : tiles) {
        t->draw();
    }

    for (auto& p : players) {
        p->draw();
    }

    for (auto& c : colliders) {
        c->draw();
    }

    SDL_RenderPresent(renderer);
}

bool Game::running() {
    return is_running;
}