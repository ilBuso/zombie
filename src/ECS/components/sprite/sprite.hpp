#ifndef SPRITE_HPP
    #define SPRITE_HPP

        #include "../../../main.hpp"

        #include "../../ECS.hpp"
        #include "../transform/transform.hpp"
 
        class Sprite : public Component {
            private:
                Transform* transform;
                SDL_Texture* texture;
                SDL_Rect src_rect, dest_rect;

            public:
                Sprite() = default;
                Sprite(const char* file_path);

                void init() override;
                void update() override;
                void draw() override;

                void set_texture(const char* file_path);
        };

#endif