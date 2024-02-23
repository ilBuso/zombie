#ifndef COLLIDER_HPP
    #define COLLIDER_HPP

        #include "../../../main.hpp"

        #include "../../ECS.hpp"
        #include "../transform/transform.hpp"

        class Collider : public Component {
            private:

            public:
                SDL_Rect collider;
                std::string tag;

                Transform* transform;

                Collider(std::string tag);

                void init() override;
                void update() override;
        };
#endif