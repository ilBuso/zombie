#include "map.hpp"
#include "../game/game.hpp"
#include "../texturemanager/texturemanager.hpp"
#include <cstdlib>

Map::Map() {}

Map::~Map() {}

void Map::load_map(std::string file_path, int size_x, int size_y) {
    char c;
    std::fstream map_file;
    map_file.open(file_path);

    int src_x, src_y;

    for (int y = 0; y < size_y; y++) {
        for (int x = 0; x < size_x; x++) {
            map_file.get(c);
            src_y = atoi(&c) * 32;
            map_file.get(c);
            src_x = atoi(&c) * 32;

            Game::add_tile(src_x, src_y, x * 64, y * 64);
            map_file.ignore();
        }
    }

    map_file.close();
}
