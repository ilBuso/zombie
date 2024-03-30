#include "gameobject.hpp"

#include "../../app/world/world.hpp"

GameObject::GameObject(std::string tag, bool is_animated, Entity& m_entity)
    : entity(m_entity) {
    this->tag = tag;
    this->is_animated = is_animated;

    init();
}

void GameObject::init() {
    entity.add_component<Time>();
    entity.add_component<Transform>(3);
    entity.add_component<Collider>(tag);
    entity.add_component<Sprite>(tag, is_animated);
    entity.add_component<KeyboardController>();
    entity.add_group(World::players_group);
}