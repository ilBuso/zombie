#ifndef TEXTUREMANAGER_HPP
#define TEXTUREMANAGER_HPP

    #include "../main.hpp"

    class TextureManager {

        private:


        public:
            static SDL_Texture* load_texture(const char* file_path);
    };

#endif