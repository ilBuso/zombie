#ifndef ASSETMANAGER_HPP
    #define ASSETMANAGER_HPP

        #include "../main.hpp"

        #include "../texturemanager/texturemanager.hpp"
        #include "../vector2d/vector2d.hpp"
        #include "../ECS/ECS.hpp"

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