#include "map.hpp"
#include "../game/game.hpp"
#include "../texturemanager/texturemanager.hpp"

Map::Map() {}

Map::~Map() {}

void Map::load_map(std::string file_path, int size_x, int size_y) {
    char tile;
    std::fstream map_file;
    map_file.open(file_path);

    for (int y = 0; y < size_y; y++) {
        for (int x = 0; x < size_x; x++) {
            map_file.get(tile);
            Game::add_tile(x * 32, y * 32, atoi(&tile));
            map_file.ignore();
        }
    }

    map_file.close();
}
