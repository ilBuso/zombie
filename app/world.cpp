#include "../src/zombie.hpp"

class World : public Game {
    public:

    void init() override {
        
    }

    void update() override {

    }
};

/*
HA SENSO:
perché questo script è tipo game.cpp e se forzi l'utente a
creare un file world.cpp in cui inizializza le varie entità 
e aggiunge i componenti.

CI STA:
per la compilazione mantieni main.cpp e semplicemente invece
di usare 'Game::' usi 'World::'
*/