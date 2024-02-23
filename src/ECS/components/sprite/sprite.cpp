#include "sprite.hpp"
#include <SDL2/SDL_render.h>

Sprite::Sprite(const char* file_path) {
    set_texture(file_path);
}

Sprite::~Sprite() {
    SDL_DestroyTexture(texture);
}

void Sprite::init() {
    transform = &entity->get_component<Transform>();

    src_rect.x = src_rect.y = 0;
    src_rect.w = 128;
    src_rect.h = 128;
}

void Sprite::update() {
    dest_rect.x = static_cast<int>(transform->position.x);
    dest_rect.y = static_cast<int>(transform->position.y);
    dest_rect.w = transform->width * transform->scale;
    dest_rect.h = transform->height * transform->scale;
}

void Sprite::draw() {
    TextureManager::draw(texture, src_rect, dest_rect);
}

void Sprite::set_texture(const char* file_path) {
    texture = TextureManager::load_texture(file_path);
}