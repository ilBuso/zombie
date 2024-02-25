#ifndef SPRITE_HPP
    #define SPRITE_HPP

        #include "../../../main.hpp"

        #include "../../ECS.hpp"
        #include "../transform/transform.hpp"
        #include "../../../texturemanager/texturemanager.hpp"
        #include "../animation/animation.hpp"
 
        class Sprite : public Component {
            private:
                Transform* transform;
                SDL_Texture* texture;
                SDL_Rect src_rect, dest_rect;

                bool animated = false;
                int frames = 0;
                int speed = 100;

            public:
                int animation_index = 0;
                std::map<std::string, Animation> animations;

                SDL_RendererFlip sprite_flip = SDL_FLIP_NONE;

                Sprite() = default;
                Sprite(const char* file_path);
                Sprite(const char* file_path, bool is_animated);
                ~Sprite();


                void init() override;
                void update() override;
                void draw() override;

                void set_texture(const char* file_path);

                void play_animation(const std::string& nimation_name);
        };

#endif