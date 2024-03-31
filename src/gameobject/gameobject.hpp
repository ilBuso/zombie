#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include "../ECS/components/components.hpp"

#include <string>

class GameObject {
  private:
  public:
    Entity& entity;

    std::string tag;
    bool is_animated;

    GameObject(std::string tag, bool is_animated, Entity& m_entity);

    // virtual void init() {};
    // virtual void update() {};
};

#endif