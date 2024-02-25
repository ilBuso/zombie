#ifndef SPRITE_HPP
    #define SPRITE_HPP

        #include "../../../main.hpp"

        #include "../../ECS.hpp"
        #include "../transform/transform.hpp"
        #include "../../../texturemanager/texturemanager.hpp"
 
        class Sprite : public Component {
            private:
                Transform* transform;
                SDL_Texture* texture;
                SDL_Rect src_rect, dest_rect;

                bool animated = false;
                int frames = 0;
                int speed = 100;

            public:
                Sprite() = default;
                Sprite(const char* file_path);
                Sprite(const char* file_path, int frames_number, int m_speed);
                ~Sprite();


                void init() override;
                void update() override;
                void draw() override;

                void set_texture(const char* file_path);
        };

#endif