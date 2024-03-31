#include "player.hpp"

GameObject* Player::player = nullptr;

void Player::setup() {
    // create game object
    player = new GameObject("player", true, World::manager->add_entity());

    // add components
    player->entity.add_component<Time>();
    player->entity.add_component<Transform>(3);
    player->entity.add_component<Collider>(player->tag);
    player->entity.add_component<Sprite>(player->tag, player->is_animated);
    player->entity.add_component<KeyboardController>();
    player->entity.add_group(World::players_group);

    // animation
    Animation idle = Animation(0, 2, 500);
    Animation walk = Animation(1, 4, 100);

    // set animation
    player->entity.get_component<Sprite>().animations.emplace("idle", idle);
    player->entity.get_component<Sprite>().animations.emplace("walk", walk);

    // play idle animation
    player->entity.get_component<Sprite>().play_animation("idle");
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
            player->entity.get_component<Transform>().position.x -=
                (10 * player->entity.get_component<Transform>().velocity.x);
            player->entity.get_component<Transform>().position.y -=
                (10 * player->entity.get_component<Transform>().velocity.y);
        }
    }
}