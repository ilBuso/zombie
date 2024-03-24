#include "gameobject.hpp"

#include "../texturemanager/texturemanager.hpp"

GameObject::GameObject(std::string tag, bool is_animated,
                       Game::group_labels group)
    : gameobject(Game::manager->add_entity()) {

    gameobject.add_group(group);

    gameobject.add_component<Transform>();
    gameobject.add_component<Sprite>(tag, is_animated);
}