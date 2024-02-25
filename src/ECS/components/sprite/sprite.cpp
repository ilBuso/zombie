#include "sprite.hpp"

Sprite::Sprite(const char* file_path) {
    set_texture(file_path);
}

Sprite::Sprite(const char* file_path, int frames_number, int m_speed) {
    animated = true;

    set_texture(file_path);
    frames = frames_number;
    speed = m_speed;
}

Sprite::~Sprite() {
    SDL_DestroyTexture(texture);
}

void Sprite::init() {
    transform = &entity->get_component<Transform>();

    src_rect.x = src_rect.y = 0;
    src_rect.w = 32;
    src_rect.h = 32;
}

void Sprite::update() {
    if (animated) {
        src_rect.x =
            src_rect.w * static_cast<int>((SDL_GetTicks() / speed) % frames);
    }

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