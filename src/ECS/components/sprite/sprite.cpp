#include "sprite.hpp"
#include "../../../texturemanager/texturemanager.hpp"

Sprite::Sprite(const char* file_path) {
    set_texture(file_path);

    std::cout << "Sprite setted " << file_path << std::endl;
}

void Sprite::init() {
    transform = &entity->get_component<Transform>();

    src_rect.x = src_rect.y = 0;
    dest_rect.x = dest_rect.y = 0;

    src_rect.h = src_rect.y = 128;
    dest_rect.w = dest_rect.h = 32;
}

void Sprite::update() {
    dest_rect.x = transform->x();
    dest_rect.y = transform->y();
}

void Sprite::draw() {
    TextureManager::draw(texture, src_rect, dest_rect);
    std::cout << "yeeesss " << std::endl;
}

void Sprite::set_texture(const char* file_path) {
    texture = TextureManager::load_texture(file_path);
}