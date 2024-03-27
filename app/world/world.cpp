#include "world.hpp"
#include "../../src/zombie.hpp"

SDL_Rect World::camera = {0, 0, 1550, 1550};

Manager* World::manager = new Manager();
auto& player(World::manager->add_entity());

AssetManager* World::asset_manager = new AssetManager(manager);

auto& tiles(World::manager->get_group(World::map_group));
auto& players(World::manager->get_group(World::players_group));
auto& colliders(World::manager->get_group(World::colliders_group));

void World::setup() {
    asset_manager->add_texture("map", "assets/tiles/map.png");
    asset_manager->add_texture("collider", "assets/tiles/collider.png");
    asset_manager->add_texture("player", "assets/animations/player.png");

    map = new Map("map", 2, 32);
    map->load_map("assets/map/map.map", 32, 32);

    player.add_component<Time>();
    player.add_component<Transform>(3);
    player.add_component<Collider>("player");
    player.add_component<Sprite>("player", true);
    player.add_component<KeyboardController>();
    player.add_group(World::players_group);
}

void World::update() {
    SDL_Rect player_collider = player.get_component<Collider>().collider;
    Vector2D player_position = player.get_component<Transform>().position;

    manager->refresh();
    manager->update();

    for (auto& c : colliders) {
        SDL_Rect c_collider = c->get_component<Collider>().collider;
        if (Collision::AABB(c_collider, player_collider)) {
            player.get_component<Transform>().position = player_position;
        }
    }

    Transform player_transform = player.get_component<Transform>();

    camera.x = (player_transform.position.x +
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

/*
HA SENSO:
perché questo script è tipo game.cpp e se forzi l'utente a
creare un file world.cpp in cui inizializza le varie entità
e aggiunge i componenti.

CI STA:
per la compilazione mantieni main.cpp e semplicemente invece
di usare 'Game::' usi 'World::'
*/