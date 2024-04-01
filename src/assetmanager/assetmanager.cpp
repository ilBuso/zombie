#include "assetmanager.hpp"

#include "../game/game.hpp"

AssetManager::AssetManager(Manager* manager) {
    this->manager = manager;
}

AssetManager::~AssetManager() {}

void AssetManager::add_texture(std::string id, const char* file_path) {
    textures.emplace(id, TextureManager::load_texture(file_path));
}

SDL_Texture* AssetManager::get_texture(std::string id) {
    return textures[id];
}

void AssetManager::add_font(std::string id, const char* file_path,
                            int16_t font_size) {
    fonts.emplace(id, TTF_OpenFont(file_path, font_size));
}

TTF_Font* AssetManager::get_font(std::string id) {
    return fonts[id];
}