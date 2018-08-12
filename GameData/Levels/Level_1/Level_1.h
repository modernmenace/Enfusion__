#ifndef ENFUSION_LEVEL_1_H
#define ENFUSION_LEVEL_1_H

#include "../../Objects/Player.h"
#include "../../AI/Agent.h"
#include "../Level.h"

class Level_1 : public Level {

public:
    Level_1();

    void initialize() override;
    void update()     override;
    void render(sf::RenderWindow* window) override;
    void handleInput(sf::Keyboard::Key key) override;

private:
    Player player;
    std::vector<Agent> ai;

};

#endif //ENFUSION_LEVEL_1_H
