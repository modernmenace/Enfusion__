#ifndef ENFUSION_PLAYER_H
#define ENFUSION_PLAYER_H

#include "GameObject.h"

class Player : public GameObject {

public:
    Player(std::string spriteName, sf::Vector2f position);

    void update();
    void handleInput(sf::Keyboard::Key key);

private:
    int speed = 10;
};


#endif //ENFUSION_PLAYER_H
