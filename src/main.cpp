#include "../app/world/world.hpp"
#include "./game/game.hpp"

int main() {

    // Create game instance
    Game* game = new Game();
    World* world = new World();

    // Initialize game
    game->init();

    // Inital setup
    world->setup();

    // Game loop
    while (game->running()) {
        game->handle_events();
        world->update();
        world->render();
    }

    // Close game
    game->kill();

    // End
    return 0;
}