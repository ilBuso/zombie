#include "transform.hpp"

#include <math.h>

Transform::Transform() {
    position.zero();
}

Transform::Transform(float x, float y) {
    position.x = x;
    position.y = y;
}

Transform::Transform(int scale) {
    position.x = 600;
    position.y = 600;
    this->scale = scale;
}

Transform::Transform(float x, float y, int width, int height, int scale) {
    position.x = x;
    position.y = y;

    this->width = width;
    this->height = height;

    this->scale = scale;
}

void Transform::init() {
    velocity.zero();

    if (entity->has_component<Time>()) {
        time = &entity->get_component<Time>();
    }
}

void Transform::update() {
    if (entity->has_component<Time>()) {
        if (velocity.x != 0 && velocity.y != 0) {
            normalize_velocity();
        }

        position.x += velocity.x * speed * time->delta_time;
        position.y += velocity.y * speed * time->delta_time;
    }
}

void Transform::normalize_velocity() {
    float result = sqrt(pow(velocity.x, 2) + pow(velocity.y, 2));
    velocity.x /= result;
    velocity.y /= result;
}