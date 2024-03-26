#ifndef GAME_HPP
#define GAME_HPP

#include "../ECS/components/time/time.hpp"
#include "../assetmanager/assetmanager.hpp"

#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>

class Collider;
class World;

class Game {
  private:
    SDL_Window* window = nullptr;

  public:
    static SDL_Renderer* renderer;
    static SDL_Event event;
    static bool is_running;

    static int window_width;
    static int window_height;

    Game();
    ~Game();

    /// Functions
    bool init();
    virtual void setup(){};
    void kill();

    void handle_events();
    virtual void update(){};
    virtual void render(){};

    bool running();
};

#endif
