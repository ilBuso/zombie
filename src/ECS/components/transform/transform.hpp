#ifndef TRANSFORM_HPP
    #define TRANSFORM_HPP

        #include "../../../main.hpp"

        #include "../../ECS.hpp"
        #include "../../../vector2d/vector2d.hpp"

        class Transform : public Component {
            private:

            public:
                Vector2D position;

                Transform();
                Transform(float x, float y); 

                void update() override;
        };
#endif