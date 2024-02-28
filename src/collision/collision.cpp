#include "collision.hpp"

#include "../ECS/components/collider/collider.hpp"

bool Collision::AABB(const SDL_Rect& rect_a, const SDL_Rect& rect_b) {
    if (rect_a.x + rect_a.w >= rect_b.x && rect_b.x + rect_b.w >= rect_a.x &&
        rect_a.y + rect_a.h >= rect_b.y && rect_b.y + rect_b.h >= rect_a.y) {
        return true;
    }
    return false;
}

bool Collision::AABB(const Collider& collider_a, const Collider& collider_b) {
    if (AABB(collider_a.collider, collider_b.collider)) {
        return true;
    } else {
        return false;
    }
}