#ifndef ENFUSION_AGENT_H
#define ENFUSION_AGENT_H

#include "../Core/Engine.h"

class Agent {

public:
    Agent(std::string spriteName, sf::Vector2f position);

    void render(sf::RenderWindow *window);

private:
    sf::Sprite   sprite;
    sf::Vector2f position;

};

#endif //ENFUSION_AGENT_H
