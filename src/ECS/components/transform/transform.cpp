#include "transform.hpp"

Transform::Transform() {
    position.x = 0;
    position.y = 0;
}

Transform::Transform(float x, float y) {
    position.x = x;
    position.y = y;
}

void Transform::update() {
    /*position.x++;
    position.y++;*/
}