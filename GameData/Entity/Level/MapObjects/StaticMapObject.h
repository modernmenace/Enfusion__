#ifndef ENFUSION___STATICMAPOBJECT_H
#define ENFUSION___STATICMAPOBJECT_H

#include <bitset>
#include "../../../Engine/Entity/Entity.h"
#include "../../Player.h"

struct Tile;

class StaticMapObject : public Entity {

public:
    StaticMapObject(string_t tileset, sf::IntRect texBounds);
    StaticMapObject(const StaticMapObject& obj);

    virtual void setPosition(Tile&);
    virtual void collideWithPlayer(Player&);

    void update(sf::Time tickRate)        override;
    virtual uint16_t zOrderBoundary();

    inline bool          inView()  { return o_inView; }
    inline Tile*         tile()    { return o_tile; }

    sf::Vector2u  center();
    sf::FloatRect bounds() ;

    virtual StaticMapObject* createCopy() { return new StaticMapObject(*this); };

protected:
    sf::Rect<uint32_t> o_tiles;
    sf::IntRect        o_bounds;
    unsigned int       o_tileWidth;
    unsigned int       o_tileHeight;
    string_t           o_tileset;

    bool    o_inView = false;
    Tile*   o_tile   = nullptr;

};


#endif //ENFUSION___STATICMAPOBJECT_H
