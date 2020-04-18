#ifndef ENFUSION_LEVEL_1_H
#define ENFUSION_LEVEL_1_H

#include "../../Engine/Entity/Player.h"
#include "../../Engine/AI/Agent.h"
#include "../../Engine/Lvl/Level.h"
#include "../../Engine/Lvl/Tilemap.h"
#include "../../Engine/Entity/UI/Hotbar.h"
#include "../../Engine/Entity/UI/InventoryMenu.h"

#ifdef DEBUG_BUILD
#include "../../Engine/Entity/UI/TextDisplay.h"
#include "../../Engine/Entity/UI/PauseMenu.h"

#endif

class Level_1 : public Level {

public:
    Level_1();

    void initialize() override;

    void update(sf::Time tickRate)          override;
    void render(sf::RenderWindow* window)   override;
    void handleInput(sf::Keyboard::Key key) override;


private:
    Player   player;
    Hotbar   hotbar;
    Tilemap* map;
    InventoryMenu i_menu;
    PauseMenu     p_menu;

    #ifdef DEBUG_BUILD
    TextDisplay* playerPosDebugText = nullptr;
    #endif

};

#endif //ENFUSION_LEVEL_1_H
