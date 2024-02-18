#ifndef TRANSFORM_HPP
    #define TRANSFORM_HPP

        #include "../../../main.hpp"

        #include "../../ECS.hpp"

        class Transform : public Component {
            private:
                float x_position;
                float y_position; 

            public:
                Transform();
                Transform(float x, float y); 

                float x();
                float y();

                void init() override;
                void update() override;
                void draw() override;

                void set_position(float x, float y);

        };
#endif