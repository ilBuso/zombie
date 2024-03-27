#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "../../src/zombie.hpp"

class Player : public Entity {
  public:
    static Entity* player;

    void init() override;
    void update() override;
};

#endif