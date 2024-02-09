#ifndef GAME_HPP
    #define GAME_HPP

        #include "../main.hpp"

        class Game {

            private:
                bool is_running = false;
                int last_frame_time = 0;
                SDL_Window* window = NULL;
                SDL_Renderer* renderer = NULL;

                SDL_Texture* player_texture = NULL;
                SDL_Rect src_rect, dest_rect;

            public:
                Game();     // Constructor
                ~Game();    // Destroyer

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
