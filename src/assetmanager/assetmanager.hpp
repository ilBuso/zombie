#ifndef ASSETMANAGER_HPP
#define ASSETMANAGER_HPP

#include "../ECS/ECS.hpp"
#include "../texturemanager/texturemanager.hpp"

#include "../ECS/components/components.hpp"

#include <map>
#include <string>

class AssetManager {
  private:
    Manager* manager;
    std::map<std::string, SDL_Texture*> textures;

  public:
    AssetManager(Manager* Manager);
    ~AssetManager();

    void add_texture(std::string id, const char* file_path);
    SDL_Texture* get_texture(std::string id);
};
#endif