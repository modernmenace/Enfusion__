#ifndef ENFUSION_AGENT_H
#define ENFUSION_AGENT_H

#include "../Core/Engine.h"
#include "../Entity/Entity.h"
#include "../Component/Base/Sprite.h"

class Agent : public Entity {

public:
    Agent(std::string spriteName, sf::Vector2f position);
    void render(sf::RenderWindow* window);

private:
    sf::Vector2f position;

};

#endif //ENFUSION_AGENT_H
