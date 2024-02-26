#include "keyboardcontroller.hpp"
#include <SDL2/SDL_scancode.h>

void KeyboardController::init() {
    transform = &entity->get_component<Transform>();
    sprite = &entity->get_component<Sprite>();
}

void KeyboardController::update() {
    keystates = SDL_GetKeyboardState(NULL);

    if (keystates[SDL_SCANCODE_ESCAPE]) {
        Game::is_running = false;
    }

    if (keystates[SDL_SCANCODE_W]) {
        transform->velocity.y = -1;
    } else if (keystates[SDL_SCANCODE_S]) {
        transform->velocity.y = 1;
    } else {
        transform->velocity.y = 0;
    }

    if (keystates[SDL_SCANCODE_A]) {
        transform->velocity.x = -1;
        sprite->sprite_flip = SDL_FLIP_HORIZONTAL;
    } else if (keystates[SDL_SCANCODE_D]) {
        transform->velocity.x = 1;
        sprite->sprite_flip = SDL_FLIP_NONE;
    } else {
        transform->velocity.x = 0;
    }

    if (transform->velocity.x != 0 || transform->velocity.y != 0) {
        sprite->play_animation("walk");
    }
    if (transform->velocity.y == 0 && transform->velocity.x == 0) {
        sprite->play_animation("idle");
    }
}
