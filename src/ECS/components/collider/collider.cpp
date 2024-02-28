#include "collider.hpp"

#include "../../../game/game.hpp"
#include "../../../texturemanager/texturemanager.hpp"

#include <SDL2/SDL_render.h>

Collider::Collider(std::string tag) {
    this->tag = tag;
}

Collider::Collider(std::string tag, int x, int y, int size) {
    this->tag = tag;
    collider.x = x;
    collider.y = y;
    collider.w = collider.h = size;
}

void Collider::init() {
    if (!entity->has_component<Transform>()) {
        entity->add_component<Transform>();
    }
    transform = &entity->get_component<Transform>();

    texture = TextureManager::load_texture("assets/tiles/collider.png");
    src_rect = {0, 0, 32, 32};
    dest_rect = {collider.x, collider.y, collider.w, collider.h};
}

void Collider::update() {
    if (tag != "map") {
        collider.x = transform->position.x;
        collider.y = transform->position.y;
        collider.w = transform->width * transform->scale;
        collider.h = transform->height * transform->scale;
    }

    dest_rect.x = collider.x - Game::camera.x;
    dest_rect.y = collider.y - Game::camera.y;
}

void Collider::draw() {
    TextureManager::draw(texture, src_rect, dest_rect, SDL_FLIP_NONE);
}