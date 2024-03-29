#ifndef COLLIDER_HPP
#define COLLIDER_HPP

#include "../../ECS.hpp"
#include "../transform/transform.hpp"

#include <SDL2/SDL_render.h>

class Collider : public Component {
  private:
  public:
    SDL_Rect collider;
    std::string tag;

    Transform* transform;

    SDL_Texture* texture;
    SDL_Rect src_rect, dest_rect;

    Collider(std::string tag);
    Collider(std::string tag, int x, int y, int size);

    void init() override;
    void update() override;
    void draw() override;
};
#endif