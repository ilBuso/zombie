#include "ECS.hpp"

inline component_type_id get_component_type_id(){
    static component_type_id last_id = 0;
    return last_id++;
}

template <typename T> inline component_type_id get_component_id() noexcept {
    static component_type_id type_id = get_component_type_id();
    return type_id;
}

void Entity::update() {
    for (auto& c : components) {
        c->update();
    }
    for (auto& c : components) {
        c->draw();
    }
}

bool Entity::is_active(){
    return active;
}

void Entity::destroy() {
    active = false;
}

template <typename T> bool Entity::has_components() const {
    return component_bitset[get_component_id<T>];
}