#ifndef GAMEOBJECT_HPP
    #define GAMEOBJECT_HPP

        #include "../main.hpp"

        #include "../texturemanager/texturemanager.hpp"

        class GameObject {
            
            private:
                float x_position;
                float y_position;
                float width;
                float height;
                float velocity = 0.0f;

                SDL_Renderer* renderer;
                SDL_Texture* texture;
                SDL_Rect src_rect, dest_rect;

            public:
                GameObject(const char* texture, SDL_Renderer* renderer);
                ~GameObject();
            
                void update();
                void render();
        };

#endif