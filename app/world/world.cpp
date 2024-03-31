#include "world.hpp"

#include "../../src/zombie.hpp"

#include "../player/player.hpp"

SDL_Rect World::camera = {0, 0, 140, 970};

Manager* World::manager = new Manager();
AssetManager* World::asset_manager = new AssetManager(manager);

std::vector<Entity*>& World::tiles(World::manager->get_group(World::map_group));
std::vector<Entity*>&
    World::players(World::manager->get_group(World::players_group));
std::vector<Entity*>&
    World::colliders(World::manager->get_group(World::colliders_group));

void World::setup() {
    asset_manager->add_texture("map", "assets/tiles/map.png");
    asset_manager->add_texture("collider", "assets/tiles/collider.png");
    asset_manager->add_texture("player", "assets/animations/player.png");

    map = new Map("map", 2, 32);
    map->load_map("assets/map/map.map", 32, 32);
}

void World::update() {

    manager->refresh();
    manager->update();

    Transform player_transform =
        Player::player->entity.get_component<Transform>();

    camera.x = (Player::player->entity.get_component<Transform>().position.x +
                ((player_transform.width * player_transform.scale) / 2.0f)) -
               (Game::window_width / 2.0f);
    camera.y = (player_transform.position.y +
                ((player_transform.width * player_transform.scale) / 2.0f)) -
               (Game::window_height / 2.0f);

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

void World::render() {
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