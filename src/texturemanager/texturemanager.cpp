#include "texturemanager.hpp"

SDL_Texture* TextureManager::load_texture(const char* file_path, SDL_Renderer* renderer) {
    SDL_Surface* temp_surface = IMG_Load(file_path);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, temp_surface);
    SDL_FreeSurface(temp_surface);

    return texture;
}