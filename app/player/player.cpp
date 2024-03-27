#include "player.hpp"

#include "../world/world.hpp"
#include <iostream>

Entity& Player::player(World::manager->add_entity());

void Player::init() {
    Entity::init();

    player.add_component<Time>();
    player.add_component<Transform>(3);
    player.add_component<Collider>("player");
    player.add_component<Sprite>("player", true);
    player.add_component<KeyboardController>();
    player.add_group(World::players_group);
}

void Player::update() {
    Entity::update();
}
