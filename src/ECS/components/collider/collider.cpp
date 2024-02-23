#include "collider.hpp"

Collider::Collider(std::string tag) {
    this->tag = tag;
}

void Collider::init() {
    if (!entity->has_components<Transform>()){
       entity->add_component<Transform>(); 
    }
    transform = &entity->get_component<Transform>();
}

void Collider::update() {
    collider.x = transform->position.x;
    collider.y = transform->position.y;
    collider.w = transform->width * transform->scale;
    collider.h = transform->height * transform->scale;
}