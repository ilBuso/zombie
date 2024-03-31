#include "player.hpp"

GameObject* Player::player = nullptr;

void Player::setup() {
    player = new GameObject("player", true, World::manager->add_entity());

    player->entity.add_component<Time>();
    player->entity.add_component<Transform>(3);
    player->entity.add_component<Collider>(player->tag);
    player->entity.add_component<Sprite>(player->tag, player->is_animated);
    player->entity.add_component<KeyboardController>();
    player->entity.add_group(World::players_group);
}

void Player::update() {
    if (player == nullptr) {
        return;
    }

    SDL_Rect player_collider =
        player->entity.get_component<Collider>().collider;
    Vector2D player_position =
        player->entity.get_component<Transform>().position;

    for (auto& c : World::colliders) {
        SDL_Rect c_collider = c->get_component<Collider>().collider;
        if (Collision::AABB(c_collider, player_collider)) {
            player->entity.get_component<Transform>().position =
                player_position;
        }
    }
}