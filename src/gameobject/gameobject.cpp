#include "gameobject.hpp"
#include "../game/game.hpp"
#include "../texturemanager/texturemanager.hpp"

GameObject::GameObject(const char* texture_file) {
    this->texture = TextureManager::load_texture(texture_file);
}

GameObject::~GameObject() {}

void GameObject::update() {
    x_position = 0;
    y_position = 0;
    width = BLOCK_WIDTH;
    height = BLOCK_HEIGHT;

    src_rect.x = 0;
    src_rect.y = 0;
    src_rect.w = ASSETS_WIDTH;
    src_rect.h = ASSETS_HEIGHT;

    dest_rect.x = x_position;
    dest_rect.y = y_position;
    dest_rect.w = width;
    dest_rect.h = height;
}

void GameObject::render() {
    SDL_RenderCopy(Game::renderer, texture, &src_rect, &dest_rect);
}