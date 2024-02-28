#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include "../main.hpp"

#include <SDL2/SDL_render.h>

class GameObject {

  private:
    float x_position;
    float y_position;
    int width;
    int height;
    int velocity = 0;

    SDL_Texture* texture;
    SDL_Rect src_rect, dest_rect;

  public:
    GameObject(const char* texture);
    ~GameObject();

    void update();
    void render();
};

#endif