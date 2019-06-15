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
#endif

class Level_1 : public Level {

public:
    Level_1();

    void initialize() override;

    void update(sf::Time tickRate)          override;
    void render(sf::RenderWindow* window)   override;

private:
    Player   player;
    Hotbar   hotbar;
    Tilemap* map;
    InventoryMenu inventory;

    #ifdef DEBUG_BUILD
    TextDisplay* playerPosDebugText = nullptr;
    #endif

};

#endif //ENFUSION_LEVEL_1_H
