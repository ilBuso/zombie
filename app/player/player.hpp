#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "../../src/zombie.hpp"

#include "../world/world.hpp"

class Player : public Game {
  private:
  public:
    static GameObject* player;
    static GameObject* label;

    Player(){};
    ~Player(){};

    void setup() override;
    void update() override;
};

#endif