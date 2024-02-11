#ifndef TEXTUREMANAGER_HPP
#define TEXTUREMANAGER_HPP

    #include "../main.hpp"
#include <SDL2/SDL_rect.h>

    class TextureManager {

        private:


        public:
            static SDL_Texture* load_texture(const char* file_path);

            static void draw(SDL_Texture* texture, SDL_Rect src_rect, SDL_Rect dest_rect);
    };

#endif