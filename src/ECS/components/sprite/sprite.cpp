#include "sprite.hpp"

#include "../../../../app/world/world.hpp"
#include "../../../game/game.hpp"

#include <SDL2/SDL_timer.h>

Sprite::Sprite(std::string texture_id) {
    set_texture(texture_id);
}

Sprite::Sprite(std::string texture_id, bool is_animated) {
    animated = is_animated;
    set_texture(texture_id);
}

Sprite::~Sprite() {}

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

    dest_rect.x = static_cast<int>(transform->position.x) - World::camera.x;
    dest_rect.y = static_cast<int>(transform->position.y) - World::camera.y;
    dest_rect.w = transform->width * transform->scale;
    dest_rect.h = transform->height * transform->scale;
}

void Sprite::draw() {
    TextureManager::draw(texture, src_rect, dest_rect, sprite_flip);
}

void Sprite::set_texture(std::string texture_id) {
    texture = World::asset_manager->get_texture(texture_id);
}

void Sprite::play_animation(const std::string& animation_name) {
    animation_index = animations[animation_name].index;
    frames = animations[animation_name].frames;
    speed = animations[animation_name].speed;
}
