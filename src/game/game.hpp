#ifndef GAME_HPP
    #define GAME_HPP

        #include "../main.hpp"
        #include "../vector2d/vector2d.hpp"

        class Game {
            private:
                bool is_running = false;
                SDL_Window* window = nullptr;
                float last_frame_time = 0.0f;

            public:
                Vector2D delta_time = Vector2D();
                static SDL_Renderer* renderer;

                Game();     // Constructor
                ~Game();    // Destructor

                /// Functions
                bool init();
                void setup();
                void kill();

                void handle_events();
                void update();
                void render();

                bool running();
        };

#endif
