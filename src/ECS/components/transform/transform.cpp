#include "transform.hpp"

Transform::Transform() {
    x_position = 0;
    y_position = 0;
}

Transform::Transform(float x, float y) {
    x_position = x;
    y_position = y;
}

float Transform::x() {
    return x_position;
}

float Transform::y() {
    return y_position;
}

void Transform::init() {
    /*x_position = 0;
    y_position = 0;*/
}

void Transform::update() {
    /*x_position++;
    y_position++;*/
}

void Transform::draw() {
    //TODO: write shit
}

void Transform::set_position(float x, float y) {
    x_position = x;
    y_position = y;
}