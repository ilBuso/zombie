#ifndef TILE_HPP
#define TILE_HPP

#include "../../../vector2d/vector2d.hpp"
#include "../../ECS.hpp"

#include <SDL2/SDL_render.h>

class Tile : public Component {
  private:
  public:
    SDL_Texture* texture;
    SDL_Rect src_rect, dest_rect;

    Vector2D position;

    Tile() = default;
    ~Tile();
    Tile(int src_x, int src_y, int x, int y, int size, int scale,
         std::string texture_id);

    void update() override;
    void draw() override;
};
#endif