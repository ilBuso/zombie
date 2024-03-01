#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include "../../ECS.hpp"

class Animation : public Component {
  private:
  public:
    int index;
    int frames;
    int speed;

    Animation();
    Animation(int index, int frames, int speed);
};
#endif