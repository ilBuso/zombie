#include "game.hpp"
#include "../ECS/ECS.hpp"
#include "../ECS/components/components.hpp"
#include "../collision/collision.hpp"
#include "../map/map.hpp"
#include "../texturemanager/texturemanager.hpp"
#include "../vector2d/vector2d.hpp"

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

std::vector<Collider*> Game::colliders;

Time d_time;

Manager manager;
auto& player(manager.add_entity());
auto& wall(manager.add_entity());

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
    Map::load_map("assets/map/16x16.map", 16, 16);

    player.add_component<Time>();
    player.add_component<Transform>();
    player.add_component<Collider>("player");
    player.add_component<KeyboardController>();
    player.add_component<Sprite>("assets/player.png");

    wall.add_component<Transform>(50.0f, 50.0f, 100.0f, 30.0f, 1.0f);
    wall.add_component<Collider>("wall");
    wall.add_component<Sprite>("assets/tiles/wall.png");
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

    for (auto cc : colliders) {
        Collision::AABB(player.get_component<Collider>(), *cc);
    }
}

void Game::render() {
    SDL_RenderClear(renderer);

    manager.draw();

    SDL_RenderPresent(renderer);
}

bool Game::running() {
    return is_running;
}

void Game::add_tile(float x, float y, int id) {
    auto& tile(manager.add_entity());
    tile.add_component<Tile>(x, y, BLOCK_WIDTH, BLOCK_HEIGHT, id);
}