#include "game.hpp"
#include "../ECS/ECS.hpp"
#include "../ECS/components/components.hpp"
#include "../collision/collision.hpp"
#include "../map/map.hpp"
#include "../texturemanager/texturemanager.hpp"
#include "../vector2d/vector2d.hpp"
#include <iostream>

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;
SDL_Rect Game::camera = {0, 0, 1550, 1550};

std::vector<Collider*> Game::colliders;

Time d_time;

Manager manager;
auto& player(manager.add_entity());
auto& wall(manager.add_entity());

bool Game::is_running = false;

const char* map_file = "assets/tiles/terrain.png";

enum group_lables : std::size_t {
    map_group,
    players_group,
    colliders_group,
};

auto& tiles(manager.get_group(map_group));
auto& players(manager.get_group(players_group));

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
    window = SDL_CreateWindow("zombie",               // Window tytle
                              SDL_WINDOWPOS_CENTERED, // X position
                              SDL_WINDOWPOS_CENTERED, // Y position
                              WINDOW_WIDTH,           // Width
                              WINDOW_HEIGHT,          // Height
                              0                       // Flags
    );
    if (!window) {
        std::cerr << "Error creating SDL Window" << std::endl;
        return false;
    }

    // Create renderer
    renderer = SDL_CreateRenderer(window, // Target
                                  -1,     // Display
                                  0       // Flags
    );
    if (!renderer) {
        std::cerr << "Error creating SDL Renderer" << std::endl;
        return false;
    }

    is_running = true;

    std::cout << "Game Started" << std::endl;
    return true;
}

void Game::kill() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    std::cout << "Game Quitted" << std::endl;
}

void Game::setup() {
    Map::load_map("assets/map/16x16.map", 32, 32);

    player.add_component<Time>();
    player.add_component<Transform>(3);
    player.add_component<Collider>("player");
    player.add_component<Sprite>("assets/animations/player-animations.png",
                                 true);
    player.add_component<KeyboardController>();
    player.add_group(players_group);

    /*wall.add_component<Transform>(50.0f, 50.0f, 100.0f, 30.0f, 1.0f);
    wall.add_component<Collider>("wall");
    wall.add_component<Sprite>("assets/tiles/wall.png");
    wall.add_group(map_group);*/
}

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
    manager.refresh();
    manager.update();

    Transform player_transform = player.get_component<Transform>();

    camera.x = (player_transform.position.x +
                ((player_transform.width * player_transform.scale) / 2.0f)) -
               (WINDOW_WIDTH / 2.0f);
    camera.y = (player_transform.position.y +
                ((player_transform.width * player_transform.scale) / 2.0f)) -
               (WINDOW_HEIGHT / 2.0f);

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

    /*for (auto cc : colliders) {
        Collision::AABB(player.get_component<Collider>(), *cc);
    }*/
}

void Game::render() {
    SDL_RenderClear(renderer);

    for (auto& t : tiles) {
        t->draw();
    }

    for (auto& p : players) {
        p->draw();
    }

    SDL_RenderPresent(renderer);
}

bool Game::running() {
    return is_running;
}

void Game::add_tile(int src_x, int src_y, int x, int y) {
    auto& tile(manager.add_entity());
    tile.add_component<Tile>(src_x, src_y, x, y, map_file);
    tile.add_group(map_group);
}