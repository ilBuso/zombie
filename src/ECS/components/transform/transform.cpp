#include "transform.hpp"

Transform::Transform() {
    position.zero();
}

Transform::Transform(float x, float y) {
    position.x = x;
    position.y = y;
}

Transform::Transform(float x, float y, float width, float height, float scale) {
    position.x = x;
    position.y = y;

    this->width = width;
    this->height = height;

    this->scale = scale;
}

void Transform::init() {
    velocity.zero();

    if (entity->has_components<Time>()) {
        time = &entity->get_component<Time>();
    }
}

void Transform::update() {
    if (entity->has_components<Time>()) {
        normalize_velocity();
        position.x += velocity.x * speed * time->delta_time;
        position.y += velocity.y * speed * time->delta_time;
    }
}

void Transform::normalize_velocity() {
    if (velocity.x != 0 || velocity.y != 0) {
        float length = sqrt(velocity.x * velocity.x + velocity.y * velocity.y);
        velocity.x /= length;
        velocity.y /= length;
    }
}