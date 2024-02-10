#ifndef MAP_HPP
    #define MAP_HPP

    #include "../main.hpp"

    class Map {
        private:
            SDL_Rect src_rect, dest_rect;

            SDL_Texture* grass;
            SDL_Texture* dirt;
            SDL_Texture* water;

            int map[MAP_WIDTH][MAP_HEIGHT];

        public:
            Map();
            ~Map();

            void load_map();
            void draw_map();
    };
            
#endif