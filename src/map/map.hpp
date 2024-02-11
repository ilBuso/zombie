#ifndef MAP_HPP
    #define MAP_HPP

    #include "../main.hpp"

    class Map {
        private:
            SDL_Rect src_rect, dest_rect;

            SDL_Texture* grass;
            SDL_Texture* dirt;
            SDL_Texture* water;
            SDL_Texture* unknown;

            int map[MAP_HEIGHT][MAP_WIDTH];

        public:
            Map();
            ~Map();

            void load_map(int array[MAP_HEIGHT][MAP_WIDTH]);
            void draw_map();
    };
            
#endif