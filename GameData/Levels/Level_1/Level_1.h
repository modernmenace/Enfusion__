#ifndef ENFUSION_LEVEL_1_H
#define ENFUSION_LEVEL_1_H

#include "../../Engine/Entity/Player.h"
#include "../../Engine/AI/Agent.h"
#include "../../Engine/Lvl/Level.h"
#include "../../Engine/Lvl/Tilemap.h"

#ifdef DEBUG_BUILD
#include "../../Engine/Entity/UI/TextDisplay.h"
#endif

class Level_1 : public Level {

public:
    Level_1();

    void initialize() override;
    void render(sf::RenderWindow* window)   override;
    void handleInput(sf::Keyboard::Key key) override;

private:
    Player   player;
    Tilemap* map;

};

#endif //ENFUSION_LEVEL_1_H
