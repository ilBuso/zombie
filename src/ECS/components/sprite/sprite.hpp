#ifndef SPRITE_HPP
#define SPRITE_HPP

#include "../../../main.hpp"

#include "../../ECS.hpp"
#include "../animation/animation.hpp"
#include "../transform/transform.hpp"

#include <SDL2/SDL_render.h>
#include <map>

class Sprite : public Component {
  private:
    Transform* transform;
    SDL_Texture* texture;
    SDL_Rect src_rect, dest_rect;

    bool animated = false;
    int frames = 0;
    int speed = 100;

  public:
    int animation_index = 0;
    std::map<std::string, Animation> animations;

    SDL_RendererFlip sprite_flip = SDL_FLIP_NONE;

    Sprite() = default;
    Sprite(std::string texture_id);
    Sprite(std::string texture_id, bool is_animated);
    ~Sprite();

    void init() override;
    void update() override;
    void draw() override;

    void set_texture(std::string texture_id);

    void play_animation(const std::string& animation_name);
};

#endif