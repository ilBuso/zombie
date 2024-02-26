#ifndef TILE_HPP
    #define TILE_HPP

        #include "../../../main.hpp"

        #include "../../ECS.hpp"
        
        class Tile : public Component {
            private:

            public:
                SDL_Texture* texture;
                SDL_Rect src_rect, dest_rect;

                Tile() = default;
                ~Tile();
                Tile(int src_x, int src_y, int x, int y, const char* file_path); 

                void draw() override;
        };
#endif