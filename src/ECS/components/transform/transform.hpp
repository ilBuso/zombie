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

                float width = BLOCK_WIDTH;
                float height = BLOCK_HEIGHT;
                float scale = BLOCK_SCALE;

                float speed = PLAYER_SPEED;

                Time* time;

                Transform();
                Transform(float x, float y);
                Transform(float x, float y, float width, float height, float scale);

                void init() override;
                void update() override;

                void normalize_velocity();
        };
#endif