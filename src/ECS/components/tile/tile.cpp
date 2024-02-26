#include "tile.hpp"
#include "../../../texturemanager/texturemanager.hpp"

Tile::~Tile() {
    SDL_DestroyTexture(texture);
}

Tile::Tile(int src_x, int src_y, int x, int y, const char* file_path) {
    texture = TextureManager::load_texture(file_path);

    src_rect.x = src_x;
    src_rect.y = src_y;
    src_rect.h = src_rect.w = 32;

    dest_rect.x = x;
    dest_rect.y = y;
    dest_rect.h = dest_rect.w = 64;
}

void Tile::draw() {
    TextureManager::draw(texture, src_rect, dest_rect, SDL_FLIP_NONE);
}