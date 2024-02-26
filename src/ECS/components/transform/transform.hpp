#ifndef TRANSFORM_HPP
    #define TRANSFORM_HPP

        #include "../../../main.hpp"

        #include "../../ECS.hpp"
        #include "../../../vector2d/vector2d.hpp"
        #include "../time/time.hpp"

        class Transform : public Component {
            private:

            public:
                Vector2D position;
                Vector2D velocity;

                int width = 32;
                int height = 32;
                int scale = 1;

                int speed = 100;

                Time* time;

                Transform();
                Transform(float x, float y);
                Transform(int scale);
                Transform(float x, float y, int width, int height, int scale);

                void init() override;
                void update() override;

                void normalize_velocity();
        };
#endif