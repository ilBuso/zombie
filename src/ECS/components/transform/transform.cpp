#include "transform.hpp"
#include <iostream>
#include <ostream>

Transform::Transform() {
    position.x = 0;
    position.y = 0;
}

Transform::Transform(float x, float y) {
    position.x = x;
    position.y = y;
}

void Transform::init() {
    velocity.x = 0;
    velocity.y = 0;

    time = &entity->get_component<Time>();
}

void Transform::update() {
    normalize_velocity();
    position.x += velocity.x * speed * time->delta_time;
    position.y += velocity.y * speed * time->delta_time;
}

void Transform::normalize_velocity() {
    if (velocity.x != 0 || velocity.y != 0) {
        float length = sqrt(velocity.x * velocity.x + velocity.y * velocity.y);
        velocity.x /= length;
        velocity.y /= length;
    }
}