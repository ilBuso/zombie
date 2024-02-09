#include "game.hpp"

// Constructor
Game::Game() {

}

// Destroyer
Game::~Game() {

}


/// Functions
bool Game::init(void) {

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cerr << "Error Initializing SDL" << std::endl;
        return false;
    }

    // Create window
    window = SDL_CreateWindow(
        "zombie",                   // Window tytle
        SDL_WINDOWPOS_CENTERED,     // X position
        SDL_WINDOWPOS_CENTERED,     // Y position
        WINDOW_WIDTH,               // Width
        WINDOW_HEIGHT,              // Height
        0                           // Flags
    );
    if (!window) {
        std::cerr << "Error creating SDL Window" << std::endl;
        return false;
    }

    // Create renderer
    renderer = SDL_CreateRenderer(
        window,     // Target
        -1,         // Display
        0           // Flags
    );
    if (!renderer) {
        std::cerr << "Error creating SDL Renderer" << std::endl;
        return false;
    }

    is_running = true;

    // texture
    player_texture = TextureManager:: load_texture("assets/player.png", renderer);

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

    dest_rect.w = PLAYER_WIDTH;
    dest_rect.h = PLAYER_HEIGHT;

}

void Game::render() {
    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, player_texture, NULL, &dest_rect);

    SDL_RenderPresent(renderer);
}

bool Game::running() {
    return is_running;
}
