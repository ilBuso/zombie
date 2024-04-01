#ifndef LABEL_HPP
#define LABEL_HPP

#include "../../../ECS.hpp"

#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>

class UI_Label : public Component {
  private:
    SDL_Rect position;

    const char* label_text;
    const char* label_font;

    SDL_Color text_color;
    SDL_Texture* label_texture;

  public:
    UI_Label(int x, int y, const char* text, const char* font,
             SDL_Color& color);
    ~UI_Label(){};

    void set_label_text(const char* text, const char* font);

    void draw() override;
};

#endif