#include "./game/game.hpp"

int main() {

    // Create game instance
    Game* game = new Game();

    // Initialize game
    game->init();

    // Inital setup
    game->setup();

    // Game loop
    while(game->running()) {
        game->handle_events();
        game->update();
        game->render();
    }

    // Close game
    game->kill();

    // End
    return 0;
}

// float delta_time = (SDL_GetTicks() - last_frame_time) / 1000.0f