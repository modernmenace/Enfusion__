#ifndef ENFUSION_POSITION_H
#define ENFUSION_POSITION_H

#include "../Component.h"
#include "../../../Lvl/LvlStructs.h"

class Position : public Component {

public:
    Position(sf::Vector2f position);
    void setPosition(sf::Vector2f pos);
    void setPosition(Tile*);

    inline sf::Vector2f getPosition() { return p_pos;  }
    inline Tile*        getTile()     { return p_tile; }

private:
    sf::Vector2f p_pos;
    Tile*        p_tile = nullptr;

};


#endif //ENFUSION_POSITION_H
