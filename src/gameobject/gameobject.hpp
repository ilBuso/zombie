#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include "../ECS/components/components.hpp"
#include "../game/game.hpp"

#include <string>

#include <SDL2/SDL_render.h>

class GameObject {
  private:
  public:
    Entity& gameobject;

    GameObject(std::string tag, bool is_animated, Game::group_labels group);
};

#endif