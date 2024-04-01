#include "game.hpp"

#include "../../app/world/world.hpp"
#include "../ECS/components/components.hpp"
#include "../collision/collision.hpp"
#include "../map/map.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_video.h>

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

bool Game::is_running = false;

int Game::window_width = 0;
int Game::window_height = 0;

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

    if (TTF_Init() != 0) {
        std::cerr << "Error initializing SDL_ttf" << std::endl;
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

bool Game::running() {
    return is_running;
}