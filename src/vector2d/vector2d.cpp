#include "vector2d.hpp"

Vector2D::Vector2D() {
    x = 0.0f;
    y = 0.0f;
}

Vector2D::Vector2D(float x, float y) {
    this->x = x;
    this->y = y;
}


Vector2D& Vector2D::add(const Vector2D& vector) {
    this->x += vector.x;
    this->y += vector.y;

    return  *this;
}

Vector2D& Vector2D::sub(const Vector2D& vector) {
    this->x -= vector.x;
    this->y -= vector.y;

    return  *this;
}

Vector2D& Vector2D::mult(const Vector2D& vector) {
    this->x *= vector.x;
    this->y *= vector.y;

    return  *this;
}

Vector2D& Vector2D::div(const Vector2D& vector) {
    this->x /= vector.x;
    this->y /= vector.y;

    return  *this;
}


Vector2D& operator+(Vector2D& vec_one, const Vector2D& vec_two) {
    return vec_one.add(vec_two);
}

Vector2D& operator-(Vector2D& vec_one, const Vector2D& vec_two) {
    return vec_one.sub(vec_two);
}

Vector2D& operator*(Vector2D& vec_one, const Vector2D& vec_two) {
    return vec_one.mult(vec_two);
}

Vector2D& operator/(Vector2D& vec_one, const Vector2D& vec_two) {
    return vec_one.div(vec_two);
}


Vector2D& Vector2D::operator+=(const Vector2D& vector) {
    return this->add(vector);
}

Vector2D& Vector2D::operator-=(const Vector2D& vector) {
    return this->sub(vector);
}

Vector2D& Vector2D::operator*=(const Vector2D& vector) {
    return this->mult(vector);
}

Vector2D& Vector2D::operator/=(const Vector2D& vector) {
    return this->div(vector);
}


Vector2D& Vector2D::operator*(const int& i) {
    this->x *= i;
    this->y *= i;

    return *this;
}

Vector2D& Vector2D::zero() {
    this->x = 0;
    this->y = 0;

    return *this;
}