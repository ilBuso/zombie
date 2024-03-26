#ifndef PLAYER_HPP
#define PLAYER_HPP
    #include "../../src/zombie.hpp"
    #include "../world/world.hpp"

    class Player : public Script {
    public:
        void init() override;
        void update() override;
    };

#endif