#ifndef GAME_HPP
    #define GAME_HPP

        #include "../main.hpp"
        #include "../vector2d/vector2d.hpp"

        class Collider;

        class Game {
            private:
                bool is_running = false;
                SDL_Window* window = nullptr;

            public:
                static SDL_Renderer* renderer;
                static SDL_Event event;
                static std::vector<Collider*> colliders;

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
