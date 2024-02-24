#include "map.hpp"
#include "../texturemanager/texturemanager.hpp"
#include <SDL2/SDL_render.h>

// clang-format off
int lvl1[MAP_HEIGHT][MAP_WIDTH] = {
    {0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 2, 2, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};
// clang-format on

Map::Map() {
    ground = TextureManager::load_texture("assets/tiles/ground.png");
    wall = TextureManager::load_texture("assets/tiles/wall.png");
    unknown = TextureManager::load_texture("assets/tiles/unknown.png");

    load_map(lvl1);

    src_rect.x = src_rect.y = 0;
    dest_rect.x = dest_rect.y = 0;

    src_rect.w = src_rect.h = ASSETS_HEIGHT;
    dest_rect.w = dest_rect.h = BLOCK_HEIGHT;
}

Map::~Map() {
    SDL_DestroyTexture(ground);
    SDL_DestroyTexture(wall);
    SDL_DestroyTexture(unknown);
}

void Map::load_map(int array[MAP_HEIGHT][MAP_WIDTH]) {
    for (int row = 0; row < MAP_HEIGHT; row++) {
        for (int column = 0; column < MAP_WIDTH; column++) {
            map[row][column] = array[row][column];
        }
    }
}

void Map::draw_map() {
    int type = 0;

    for (int row = 0; row < MAP_HEIGHT; row++) {
        for (int column = 0; column < MAP_WIDTH; column++) {
            type = map[row][column];

            dest_rect.x = column * 32;
            dest_rect.y = row * 32;

            switch (type) {
                case 0:
                    TextureManager::draw(ground, src_rect, dest_rect);
                    break;
                case 1:
                    TextureManager::draw(wall, src_rect, dest_rect);
                    break;
                default:
                    TextureManager::draw(unknown, src_rect, dest_rect);
                    break;
            }
        }
    }
}