#ifndef ENFUSION_LEVEL_1_H
#define ENFUSION_LEVEL_1_H

#include "../../Engine/Entity/Player.h"
#include "../../Engine/AI/Agent.h"
#include "../../Engine/Lvl/Level.h"
#include "../../Engine/Lvl/Tilemap.h"
#include "../../Engine/Entity/UI/Menus/Hotbar.h"
#include "../../Engine/Entity/UI/Menus/InventoryMenu.h"

#ifdef DEBUG_BUILD
#include "../../Engine/Entity/UI/Elements/TextDisplay.h"
#include "../../Engine/Entity/UI/Menus/PauseMenu.h"
#include "../../Engine/Entity/UI/Elements/Minimap.h"

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
    Minimap       minimap;

    #ifdef DEBUG_BUILD
    TextDisplay* playerPosDebugText = nullptr;
    #endif

};

#endif //ENFUSION_LEVEL_1_H
