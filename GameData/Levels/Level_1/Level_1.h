#ifndef ENFUSION_LEVEL_1_H
#define ENFUSION_LEVEL_1_H

#include "../../Engine/Entity/Player.h"
#include "../../Engine/AI/Agent.h"
#include "../../Engine/Lvl/Level.h"

class Level_1 : public Level {

public:
    Level_1();

    void initialize() override;
    void update(sf::Time tickRate)          override;
    void render(sf::RenderWindow* window)   override;
    void handleInput(sf::Keyboard::Key key) override;

private:
    Player player;
    std::vector<Entity*> entities;
    std::vector<Entity*> ai;

};

#endif //ENFUSION_LEVEL_1_H
