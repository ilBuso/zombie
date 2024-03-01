#ifndef MAP_HPP
#define MAP_HPP

#include <string>

class Map {
  private:
    std::string texture_id;
    int scale;
    int tile_size;

    int scaled_size;

  public:
    Map(std::string texture_id, int scale, int tile_size);
    ~Map();

    void add_tile(int src_x, int src_y, int x, int y);
    void load_map(std::string file_path, int x, int y);
};

#endif