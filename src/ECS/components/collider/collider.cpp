#include "collider.hpp"
#include "../../../game/game.hpp"

Collider::Collider(std::string tag) {
    this->tag = tag;
}

void Collider::init() {
    if (!entity->has_component<Transform>()){
       entity->add_component<Transform>(); 
    }
    transform = &entity->get_component<Transform>();

    Game::colliders.push_back(this);
}

void Collider::update() {
    collider.x = transform->position.x;
    collider.y = transform->position.y;
    collider.w = transform->width * transform->scale;
    collider.h = transform->height * transform->scale;
}