#ifndef ENFUSION_LEVEL_1_H
#define ENFUSION_LEVEL_1_H

#include "../../../Entity/Player.h"
#include "../../../Engine/Lvl/Level.h"
#include "../../../Engine/Lvl/Tilemap.h"
#include "../../../Entity/UI/Menus/Hotbar.h"
#include "../../../Entity/UI/Menus/InventoryMenu.h"

#ifdef DEBUG_BUILD
#include "../../../Entity/UI/Elements/TextDisplay.h"
#include "../../../Entity/UI/Menus/PauseMenu.h"
#include "../../../Entity/UI/Elements/Minimap.h"

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
