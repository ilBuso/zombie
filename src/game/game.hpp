#ifndef GAME_HPP
    #define GAME_HPP

        #include "../main.hpp"
        #include "../vector2d/vector2d.hpp"
        #include "../ECS/components/time/time.hpp"

        class Collider;

        class Game {
            private:
                SDL_Window* window = nullptr;

            public:
                static SDL_Renderer* renderer;
                static SDL_Event event;
                static bool is_running;

                static SDL_Rect camera;

                enum group_lables : std::size_t {
                    map_group,
                    players_group,
                    colliders_group,
                };

                Time* time;

                Game();
                ~Game();

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
