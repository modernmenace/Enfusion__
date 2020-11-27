#ifndef ENFUSION_PLAYER_H
#define ENFUSION_PLAYER_H

#include "../Engine/Entity/Entity.h"
#include "../Lvl/LvlStructs.h"

class Player : public Entity {

public:
    Player(sf::Vector2f position);
    sf::FloatRect bounds() override;
    inline sf::Vector2f currentPosition();
    inline Tile& currentTile() { return *p_tile; }

    bool isMoving();

private:
    Tile* p_tile = nullptr;

};


#endif //ENFUSION_PLAYER_H
