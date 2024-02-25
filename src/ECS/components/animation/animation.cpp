#include "animation.hpp"

Animation::Animation() {}

Animation::Animation(int index, int frames, int speed) {
    this->index = index;
    this->frames = frames;
    this->speed = speed;
}