#include "ECS.hpp"

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
    entities.erase(std::remove_if(entities.begin(), entities.end(),
                                  [](const std::unique_ptr<Entity>& entity) {
                                      return !entity->is_active();
                                  }),
                   entities.end());
}

Entity& Manager::add_entity() {
    entities.emplace_back(std::make_unique<Entity>());
    return *entities.back();
}