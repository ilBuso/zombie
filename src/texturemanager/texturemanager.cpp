#include "texturemanager.hpp"

#include "../game/game.hpp"

#include <SDL2/SDL_image.h>

SDL_Texture* TextureManager::load_texture(const char* file_path) {
    SDL_Surface* temp_surface = IMG_Load(file_path);
    SDL_Texture* texture =
        SDL_CreateTextureFromSurface(Game::renderer, temp_surface);
    SDL_FreeSurface(temp_surface);

    return texture;
}

void TextureManager::draw(SDL_Texture* texture, SDL_Rect src_rect,
                          SDL_Rect dest_rect, SDL_RendererFlip renderer_flip) {
    SDL_RenderCopyEx(Game::renderer, texture, &src_rect, &dest_rect, 0, NULL,
                     renderer_flip);
}