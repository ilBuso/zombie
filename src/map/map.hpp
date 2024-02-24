#ifndef MAP_HPP
    #define MAP_HPP

    #include "../main.hpp"

    class Map {
        private:

        public:
            Map();
            ~Map();

            static void load_map(std::string file_path, int x, int y);
    };
            
#endif