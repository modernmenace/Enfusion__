#ifndef ENFUSION___STATICMAPOBJECT_H
#define ENFUSION___STATICMAPOBJECT_H

#include <bitset>
#include "../../../Engine/Core/Engine.h"

struct Tile;

class StaticMapObject {

public:
    StaticMapObject(string_t tileset, sf::IntRect texBounds);

    virtual void     setPosition(Tile&);
    virtual void     render(sf::RenderWindow* window);
    virtual uint16_t zOrderBoundary();

    inline void setTileset(string_t tileset)  { o_sprite.setTexture(AssetManager::Instance()->getTexture(tileset)); }
    inline void setBounds(sf::IntRect bounds) { o_sprite.setTextureRect(bounds); }

    inline sf::FloatRect bounds() { return o_sprite.getGlobalBounds(); }
    inline Tile*         tile()   { return o_tile; }

    sf::Vector2u center();

    virtual StaticMapObject* createCopy() { return new StaticMapObject(*this); };

protected:
    sf::Rect<uint32_t> o_tiles;
    sf::Sprite         o_sprite;
    sf::IntRect        o_bounds;
    unsigned int       o_tileWidth;
    unsigned int       o_tileHeight;

    Tile*        o_tile = nullptr;

};


#endif //ENFUSION___STATICMAPOBJECT_H
