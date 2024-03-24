#ifndef GAME_HPP
#define GAME_HPP

#include "../ECS/components/time/time.hpp"
#include "../assetmanager/assetmanager.hpp"

#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>

class Collider;

class Game {
  private:
    SDL_Window* window = nullptr;

    int window_width;
    int window_height;

  public:
    static Manager* manager;

    static SDL_Renderer* renderer;
    static SDL_Event event;
    static bool is_running;
    static SDL_Rect camera;
    static AssetManager* asset_manager;

    enum group_labels : std::size_t {
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
