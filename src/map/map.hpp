#ifndef MAP_HPP
    #define MAP_HPP

    #include "../main.hpp"

    class Map {
        private:
            const char* file_path;
            int scale;
            int tile_size;

            int scaled_size;

        public:
            Map(const char* file_path, int scale, int tile_size);
            ~Map();

            void add_tile(int src_x, int src_y, int x, int y);
            void load_map(std::string file_path, int x, int y);
    };
            
#endif