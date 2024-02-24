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

                Tile() = default;
                Tile(float x, float y, float width, float height, int id); 
        };
#endif