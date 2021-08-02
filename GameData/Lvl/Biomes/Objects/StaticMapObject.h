#ifndef ENFUSION___STATICMAPOBJECT_H
#define ENFUSION___STATICMAPOBJECT_H

#include <bitset>
#include "../../../Engine/Entity/Entity.h"
#include "../../../Entity/Player.h"

struct Tile;

class StaticMapObject : public Entity {

public:
    StaticMapObject(string_t tileset, sf::IntRect texBounds);
    StaticMapObject(const StaticMapObject& obj);

    virtual void setPosition(Tile&);
    virtual void collideWithPlayer(Player&);

    void update(sf::Time tickRate)        override;
    void render(sf::RenderWindow* window) override;
    virtual uint16_t zOrderBoundary();

    inline uint8_t       z()       { return o_z; }
    inline sf::FloatRect bounds()  { return o_sprite.getGlobalBounds(); }
    inline Tile*         tile()    { return o_tile; }

    sf::Vector2u center();

    virtual StaticMapObject* createCopy() { return new StaticMapObject(*this); };

protected:
    sf::Rect<uint32_t> o_tiles;
    sf::Sprite         o_sprite;
    sf::IntRect        o_bounds;
    unsigned int       o_tileWidth;
    unsigned int       o_tileHeight;
    string_t           o_tileset;

    uint8_t o_z    = Z_BOTTOM;
    Tile*   o_tile = nullptr;

};


#endif //ENFUSION___STATICMAPOBJECT_H
