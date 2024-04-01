#ifndef ASSETMANAGER_HPP
#define ASSETMANAGER_HPP

#include "../ECS/ECS.hpp"
#include "../texturemanager/texturemanager.hpp"

#include "../ECS/components/components.hpp"

#include <SDL2/SDL_ttf.h>

#include <cstdint>
#include <map>
#include <string>

class AssetManager {
  private:
    Manager* manager;
    std::map<std::string, SDL_Texture*> textures;
    std::map<std::string, TTF_Font*> fonts;

  public:
    AssetManager(Manager* Manager);
    ~AssetManager();

    void add_texture(std::string id, const char* file_path);
    SDL_Texture* get_texture(std::string id);

    void add_font(std::string id, const char* file_path, int16_t font_size);
    TTF_Font* get_font(std::string id);
};
#endif