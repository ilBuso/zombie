#include "map.hpp"
#include "../texturemanager/texturemanager.hpp"

int lvl1[MAP_HEIGHT][MAP_WIDTH] = {
    { 0, 1, 2, 3, 0, 0, 0, 0, 0, 0 },
    { 0, 1, 2, 3, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};

Map::Map() {
    grass = TextureManager::load_texture("assets/tiles/grass.png");
    dirt = TextureManager::load_texture("assets/tiles/dirt.png");
    water = TextureManager::load_texture("assets/tiles/water.png");
    unknown = TextureManager::load_texture("assets/tiles/unknown.png");

    load_map(lvl1);

    src_rect.x = src_rect.y = 0;
    dest_rect.x = dest_rect.y = 0;

    src_rect.w = src_rect.h = 128;
    dest_rect.w = dest_rect.h = 32;
}

Map::~Map() {

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
                    TextureManager::draw(water, src_rect, dest_rect);
                    break;
                case 1:
                    TextureManager::draw(dirt, src_rect, dest_rect);
                    break;
                case 2:
                    TextureManager::draw(grass, src_rect, dest_rect);
                    break;
                default:
                    TextureManager::draw(unknown, src_rect, dest_rect);
                    break;
            }
        }
    }
} 