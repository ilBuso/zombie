#include "tile.hpp"

#include "../../../../app/world/world.hpp"
#include "../../../texturemanager/texturemanager.hpp"

Tile::~Tile() {
    SDL_DestroyTexture(texture);
}

Tile::Tile(int src_x, int src_y, int x, int y, int size, int scale,
           std::string texture_id) {
    texture = World::asset_manager->get_texture(texture_id);

    position.x = x;
    position.y = y;

    src_rect.x = src_x;
    src_rect.y = src_y;
    src_rect.h = src_rect.w = size;

    dest_rect.x = x;
    dest_rect.y = y;
    dest_rect.h = dest_rect.w = size * scale;
}

void Tile::update() {
    dest_rect.x = position.x - World::camera.x;
    dest_rect.y = position.y - World::camera.y;
}

void Tile::draw() {
    TextureManager::draw(texture, src_rect, dest_rect, SDL_FLIP_NONE);
}