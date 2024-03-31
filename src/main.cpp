#include "./game/game.hpp"

#include "../app/world/world.hpp"

#include "../app/player/player.hpp"

int main() {

    // Create game instance
    Game* game = new Game();
    World* world = new World();
    Player* player = new Player();

    // Initialize game
    game->init();

    // Inital setup
    world->setup();
    player->setup();

    // Game loop
    while (game->running()) {
        game->handle_events();

        world->update();
        player->update();

        world->render();
    }

    // Close game
    game->kill();

    // End
    return 0;
}