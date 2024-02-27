#include "map.hpp"
#include "../ECS/components/components.hpp"
#include "../game/game.hpp"
#include "../texturemanager/texturemanager.hpp"

extern Manager manager;

Map::Map(const char* file_path, int scale, int tile_size) {
    this->file_path = file_path;
    this->scale = scale;
    this->tile_size = tile_size;
    scaled_size = tile_size * scale;
}

Map::~Map() {}

void Map::add_tile(int src_x, int src_y, int x, int y) {
    auto& tile(manager.add_entity());
    tile.add_component<Tile>(src_x, src_y, x, y, tile_size, scale, file_path);
    tile.add_group(Game::map_group);
}

void Map::load_map(std::string file_path, int size_x, int size_y) {
    char c;
    std::fstream map_file;
    map_file.open(file_path);

    int src_x, src_y;

    for (int y = 0; y < size_y; y++) {
        for (int x = 0; x < size_x; x++) {
            map_file.get(c);
            src_y = atoi(&c) * tile_size;
            map_file.get(c);
            src_x = atoi(&c) * tile_size;

            add_tile(src_x, src_y, x * scaled_size, y * scaled_size);
            map_file.ignore();
        }
    }

    map_file.ignore();

    for (int y = 0; y < size_y; y++) {
        for (int x = 0; x < size_x; x++) {
            map_file.get(c);
            if (c == '1') {
                auto& tile_collider(manager.add_entity());
                tile_collider.add_component<Collider>(
                    "map", x * scaled_size, y * scaled_size, scaled_size);
                tile_collider.add_group(Game::colliders_group);
            }
            map_file.ignore();
        }
    }

    map_file.close();
}
