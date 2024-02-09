#ifndef GAMEOBJECT_HPP
    #define GAMEOBJECT_HPP

        #include "../game/game.hpp"

        class GameObject {
            
            private:
                float x_position;
                float y_position;
                float width;
                float height;
                float velocity;

            public:
                GameObject();
                ~GameObject();

            
        };

#endif