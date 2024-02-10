#include "map.hpp"
#include "../texturemanager/texturemanager.hpp"

Map::Map() {
    grass = TextureManager::load_texture("assets/grass.png");
    dirt = TextureManager::load_texture("assets/dirt.png");
    water = TextureManager::load_texture("assets/water.png");
}

Map::~Map() {

}

void Map::load_map() {

}

void Map::draw_map() {

}