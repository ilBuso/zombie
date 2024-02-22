#ifndef TIME_HPP
    #define TIME_HPP

    #include "../../../main.hpp"

    #include "../../ECS.hpp"

    class Time : public Component {
        private:
            float last_frame_time = 0.0f;

        public:
            float delta_time;

            void update() override;
    };
#endif