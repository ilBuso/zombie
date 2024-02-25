#include "keyboardcontroller.hpp"
#include <SDL2/SDL_events.h>

void KeyboardController::init() {
    transform = &entity->get_component<Transform>();
}

void KeyboardController::update() {

    keystates = SDL_GetKeyboardState(NULL);

    if (keystates[SDL_SCANCODE_W]) {
        transform->velocity.y = -1;
    } else if (keystates[SDL_SCANCODE_S]) {
        transform->velocity.y = 1;
    } else {
        transform->velocity.y = 0;
    }

    if (keystates[SDL_SCANCODE_A]) {
        transform->velocity.x = -1;
    } else if (keystates[SDL_SCANCODE_D]) {
        transform->velocity.x = 1;
    } else {
        transform->velocity.x = 0;
    }
}