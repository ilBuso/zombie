#ifndef TILE_HPP
    #define TILE_HPP

        #include "../../../main.hpp"

        #include "../../ECS.hpp"
        #include "../transform/transform.hpp"
        #include "../sprite/sprite.hpp"
        
        class Tile : public Component {
            private:

            public:
                Transform* transform;
                Sprite* sprite;

                SDL_Rect tile_rect;
                int tile_id;
                std::string file_path;

                Tile() = default;
                Tile(float x, float y, int width, int height, int id); 

                void init() override;
        };
#endif