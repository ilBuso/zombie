#ifndef GAMEOBJECT_HPP
    #define GAMEOBJECT_HPP

        #include <iostream>
        #include <SDL2/SDL.h>
        #include "../const.hpp"

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