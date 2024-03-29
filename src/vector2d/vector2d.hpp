#ifndef VECTOR2D_HPP
#define VECTOR2D_HPP

class Vector2D {
  private:
  public:
    float x;
    float y;

    Vector2D();
    Vector2D(float x, float y);

    Vector2D& add(const Vector2D& vector);
    Vector2D& sub(const Vector2D& vector);
    Vector2D& mult(const Vector2D& vector);
    Vector2D& div(const Vector2D& vector);

    friend Vector2D& operator+(Vector2D& vec_one, const Vector2D& vec_two);
    friend Vector2D& operator-(Vector2D& vec_one, const Vector2D& vec_two);
    friend Vector2D& operator*(Vector2D& vec_one, const Vector2D& vec_two);
    friend Vector2D& operator/(Vector2D& vec_one, const Vector2D& vec_two);

    Vector2D& operator+=(const Vector2D& vector);
    Vector2D& operator-=(const Vector2D& vector);
    Vector2D& operator*=(const Vector2D& vector);
    Vector2D& operator/=(const Vector2D& vector);

    Vector2D& operator*(const int& i);
    Vector2D& zero();
};
#endif