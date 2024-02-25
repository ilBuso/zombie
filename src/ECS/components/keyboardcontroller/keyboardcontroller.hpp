#ifndef KEYBOARDCONTROLLER_HPP
    #define KEYBOARDCONTROLLER_HPP

        #include "../../../main.hpp"

        #include "../../../game/game.hpp"
        #include "../../ECS.hpp"

        #include "../transform/transform.hpp"
        #include "../sprite/sprite.hpp"

        class KeyboardController : public Component {
            private:
                const Uint8* keystates;
                
            public:
                Transform* transform;
                Sprite* sprite;

                void init() override;
                void update() override;
        };
#endif