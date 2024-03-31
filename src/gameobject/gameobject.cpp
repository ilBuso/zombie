#include "gameobject.hpp"

#include "../../app/world/world.hpp"

GameObject::GameObject(std::string tag, bool is_animated, Entity& m_entity)
    : entity(m_entity) {
    this->tag = tag;
    this->is_animated = is_animated;
}