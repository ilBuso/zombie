#include "tile.hpp"

Tile::Tile(float x, float y, int width, int height, int id) {
    tile_rect.x = x;
    tile_rect.y = y;
    tile_rect.w = width;
    tile_rect.h = height;

    tile_id = id;

    switch (tile_id) {
        case 0:
            file_path = "assets/tiles/ground.png";
            break;
        case 1:
            file_path = "assets/tiles/wall.png";
            break;
        default:
            file_path = "assets/tiles/unknown.png";
            break;
    }
}

void Tile::init() {
    entity->add_component<Transform>(tile_rect.x, tile_rect.y, tile_rect.w,
                                     tile_rect.h, 1);
    transform = &entity->get_component<Transform>();

    entity->add_component<Sprite>(file_path.c_str());
    sprite = &entity->get_component<Sprite>();
}