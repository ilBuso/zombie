#ifndef KEYBOARDCONTROLLER_HPP
    #define KEYBOARDCONTROLLER_HPP

        #include "../../../main.hpp"

        #include "../../../game/game.hpp"
        #include "../../ECS.hpp"

        #include "../transform/transform.hpp"

        class KeyboardController : public Component {
            private:

            public:
                Transform* transform;

                void init() override;
                void update() override;
        };
#endif