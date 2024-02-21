#include "game.hpp"
#include "../ECS/ECS.hpp"
#include "../ECS/components/components.hpp"
#include "../map/map.hpp"
#include "../texturemanager/texturemanager.hpp"
#include "../vector2d/vector2d.hpp"

SDL_Renderer* Game::renderer = nullptr;

Manager manager;
auto& player(manager.add_entity());

Map* map;

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
    map = new Map();

    player.add_component<Transform>();
    player.add_component<Sprite>("assets/player.png");
}

void Game::handle_events() {
    SDL_Event event;
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
    delta_time.y = delta_time.x =
        ((float)SDL_GetTicks() - last_frame_time) / 1000.0f;
    last_frame_time = (float)SDL_GetTicks();

    // manager.refresh();
    manager.update();

    // Update player position using delta_time
    player.get_component<Transform>().position.add(
        Vector2D(25, 25).mult(delta_time));
}

void Game::render() {
    SDL_RenderClear(renderer);

    map->draw_map();
    manager.draw();

    SDL_RenderPresent(renderer);
}

bool Game::running() {
    return is_running;
}
