#include "texturemanager.hpp"
#include "../game/game.hpp"

SDL_Texture* TextureManager::load_texture(const char* file_path) {
    SDL_Surface* temp_surface = IMG_Load(file_path);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer, temp_surface);
    SDL_FreeSurface(temp_surface);

    return texture;
}