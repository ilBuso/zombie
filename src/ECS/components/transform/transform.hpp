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

                float speed = 100.0f;

                Time* time;

                Transform();
                Transform(float x, float y); 

                void init() override;
                void update() override;

                void normalize_velocity();
        };
#endif