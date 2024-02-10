#include "gameobject.hpp"
#include "../texturemanager/texturemanager.hpp"
#include "../game/game.hpp"

GameObject::GameObject(const char* texture_file) {
    this->texture = TextureManager::load_texture(texture_file);
}

GameObject::~GameObject() {

}

void GameObject::update() {
    x_position = 0;
    y_position = 0;
    width = 32;
    height = 32;

    src_rect.x = 0;
    src_rect.y = 0;
    src_rect.w = 128;
    src_rect.h = 128; 

    dest_rect.x = x_position;
    dest_rect.y = y_position;
    dest_rect.w = width;
    dest_rect.h = height;
}

void GameObject::render() {
    SDL_RenderCopy(Game::renderer, texture, &src_rect, &dest_rect);
}