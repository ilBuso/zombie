#include "ECS.hpp"
#include <iterator>
#include <memory>
#include <pstl/glue_algorithm_defs.h>

void Entity::update() {
    for (auto& c : components) {
        c->update();
    }
}

void Entity::draw() {
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

bool Entity::has_group(Group m_group) {
    return group_bitset[m_group];
}

void Entity::add_group(Group m_group) {
    group_bitset[m_group] = true;
    manager.add_to_group(this, m_group);
}

void Entity::del_group(Group m_group) {
    group_bitset[m_group] = false;
}

void Manager::update() {
    for (auto& e : entities) {
        e->update();
    }
}

void Manager::draw() {
    for (auto& e : entities) {
        e->draw();
    }
}

void Manager::refresh() {
    for (auto i(0u); i < max_groups; i++) {
        auto& v(grouped_entities[i]);
        v.erase(std::remove_if(std::begin(v), std::end(v),
                               [i](Entity* m_entity) {
                                   return !m_entity->is_active() ||
                                          !m_entity->has_group(i);
                               }),
                std::end(v));
    }

    entities.erase(std::remove_if(entities.begin(), entities.end(),
                                  [](const std::unique_ptr<Entity>& entity) {
                                      return !entity->is_active();
                                  }),
                   entities.end());
}

Entity& Manager::add_entity() {
    Entity* e = new Entity(*this);
    std::unique_ptr<Entity> u_ptr{e};
    entities.emplace_back(std::move(u_ptr));
    return *e;
}

void Manager::add_to_group(Entity* m_entity, Group m_group) {
    grouped_entities[m_group].emplace_back(m_entity);
}

std::vector<Entity*>& Manager::get_group(Group m_group) {
    return grouped_entities[m_group];
}
