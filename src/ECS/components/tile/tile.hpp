#ifndef TILE_HPP
    #define TILE_HPP

        #include "../../../main.hpp"

        #include "../../ECS.hpp"
        #include "../../../vector2d/vector2d.hpp"
        
        class Tile : public Component {
            private:

            public:
                SDL_Texture* texture;
                SDL_Rect src_rect, dest_rect;

                Vector2D position;

                Tile() = default;
                ~Tile();
                Tile(int src_x, int src_y, int x, int y, const char* file_path); 

                void update() override;
                void draw() override;
        };
#endif