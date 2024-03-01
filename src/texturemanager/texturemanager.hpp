#ifndef TEXTUREMANAGER_HPP
#define TEXTUREMANAGER_HPP

#include <SDL2/SDL_render.h>

class TextureManager {
  private:
  public:
    static SDL_Texture* load_texture(const char* file_path);

    static void draw(SDL_Texture* texture, SDL_Rect src_rect,
                     SDL_Rect dest_rect, SDL_RendererFlip renderer_flip);
};

#endif