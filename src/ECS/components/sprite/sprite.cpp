#include "sprite.hpp"
#include "../../../texturemanager/texturemanager.hpp"

Sprite::Sprite(const char* file_path) {
    set_texture(file_path);
}

void Sprite::init() {
    transform = &entity->get_component<Transform>();

    src_rect.x = src_rect.y = 0;
    dest_rect.x = dest_rect.y = 0;

    src_rect.w = src_rect.h = 128;
    dest_rect.w = dest_rect.h = 32;
}

void Sprite::update() {
    dest_rect.x = (int)transform->position.x;
    dest_rect.y = (int)transform->position.y;
}

void Sprite::draw() {
    TextureManager::draw(texture, src_rect, dest_rect);
}

void Sprite::set_texture(const char* file_path) {
    texture = TextureManager::load_texture(file_path);
}