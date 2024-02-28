#include "time.hpp"

#include <SDL2/SDL_timer.h>

void Time::update() {
    float current_time = (float)SDL_GetTicks();
    delta_time = (current_time - last_frame_time) / 1000.0f;
    last_frame_time = current_time;
}
