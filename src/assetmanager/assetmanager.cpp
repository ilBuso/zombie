#include "assetmanager.hpp"

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