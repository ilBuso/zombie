#include "label.hpp"

#include "../../../../../app/world/world.hpp"

#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>

UI_Label::UI_Label(int x, int y, const char* text, const char* font,
                   SDL_Color& color)
    : label_text(text), label_font(font), text_color(color) {
    position.x = x;
    position.y = y;

    set_label_text(label_text, label_font);
}

void UI_Label::set_label_text(const char* text, const char* font) {
    SDL_Surface* surface = TTF_RenderText_Blended(
        World::asset_manager->get_font(font), text, text_color);
    label_texture = SDL_CreateTextureFromSurface(World::renderer, surface);
    SDL_FreeSurface(surface);

    SDL_QueryTexture(label_texture, nullptr, nullptr, &position.w, &position.h);
}

void UI_Label::draw() {
    SDL_RenderCopy(World::renderer, label_texture, nullptr, &position);
}