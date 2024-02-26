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
                static std::vector<Collider*> colliders;
                static bool is_running;

                static SDL_Rect camera;

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

                static void add_tile(int src_x, int src_y, int x, int y);
        };

#endif
