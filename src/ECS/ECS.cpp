#include "ECS.hpp"
#include <memory>
#include <utility>

inline component_type_id get_component_type_id() {
    static component_type_id last_id = 0;
    return last_id++;
}

template <typename T>
inline component_type_id get_component_id() noexcept {
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

bool Entity::is_active() {
    return active;
}

void Entity::destroy() {
    active = false;
}

template <typename T>
bool Entity::has_components() const {
    return component_bitset[get_component_id<T>];
}

template <typename T, typename... T_args>
T& Entity::add_component(T_args&&... m_args) {
    T* c(new T(std::forward<T_args>(m_args)...));
    c->entity = this;
    std::unique_ptr<Component> u_ptr{c};
    components.emplace_back(std::move(u_ptr));

    component_array[get_component_type_id<T>()] = c;
    component_bitset[get_component_type_id<T>()] = true;

    c->init();
    return c;
}

template <typename T>
T& Entity::get_component() const {
    auto ptr(component_array[get_component_type_id<T>()]);
    return *static_cast<T*>(ptr);
}