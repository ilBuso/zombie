#include "gameobject.hpp"

#include "../texturemanager/texturemanager.hpp"

GameObject::GameObject(std::string tag, bool is_animated,
                       Game::group_labels group)
    : gameobject(Game::manager->add_entity()) {

    gameobject.add_group(group);

    gameobject.add_component<Transform>();
    gameobject.add_component<Sprite>(tag, is_animated);
}

/*

una bella idea è se fai le funzioni che ti aggiungono il
componente specifico tipo `add_transform()` le quali si
ti aggiungono il componenti ma prima di farlo controllano
che ci siano tutti i componenti necessari.

*/