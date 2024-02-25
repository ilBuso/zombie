#include "sprite.hpp"
#include <iostream>
#include <ostream>

Sprite::Sprite(const char* file_path) {
    set_texture(file_path);
}

Sprite::Sprite(const char* file_path, bool is_animated) {
    animated = is_animated;

    Animation idle = Animation(0, 2, 100);
    Animation walk = Animation(1, 4, 100);

    animations.emplace("idle", idle);
    animations.emplace("walk", walk);

    play_animation("idle");

    set_texture(file_path);
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
    if (animated && speed != 0) {
        src_rect.x =
            src_rect.w * static_cast<int>((SDL_GetTicks() / speed) % frames);
    }

    src_rect.y = animation_index * transform->height;

    dest_rect.x = static_cast<int>(transform->position.x);
    dest_rect.y = static_cast<int>(transform->position.y);
    dest_rect.w = transform->width * transform->scale;
    dest_rect.h = transform->height * transform->scale;
}

void Sprite::draw() {
    TextureManager::draw(texture, src_rect, dest_rect, sprite_flip);
}

void Sprite::set_texture(const char* file_path) {
    texture = TextureManager::load_texture(file_path);
}

void Sprite::play_animation(const std::string& animation_name) {
    animation_index = animations[animation_name].index;
    frames = animations[animation_name].frames;
    speed = animations[animation_name].speed;
}
