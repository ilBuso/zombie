#ifndef WORLD_HPP
#define WORLD_HPP
#include "../../src/zombie.hpp"

class World : public Game {
  private:
  public:
    static Manager* manager;

    static SDL_Rect camera;
    static AssetManager* asset_manager;

    //******
    Time d_time;
    Map* map;

    static GameObject* player;

    enum group_labels : std::size_t {
        map_group,
        players_group,
        colliders_group,
    };

    //******

    World(){};
    ~World(){};

    void setup() override;
    void update() override;
    void render() override;
};

#endif