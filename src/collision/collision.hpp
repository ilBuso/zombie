#ifndef COLLISION_HPP
    #define COLLISION_HPP

        #include "../main.hpp"

        class Collision {
            private:

            public:
                static bool AABB(const SDL_Rect& rect_a, const SDL_Rect& rect_b);
        };
#endif