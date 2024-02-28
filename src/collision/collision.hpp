#ifndef COLLISION_HPP
#define COLLISION_HPP

#include "../main.hpp"

#include <SDL2/SDL_rect.h>

class Collider;

class Collision {
  private:
  public:
    static bool AABB(const SDL_Rect& rect_a, const SDL_Rect& rect_b);
    static bool AABB(const Collider& collider_a, const Collider& collider_b);
};
#endif