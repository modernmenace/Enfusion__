#ifndef ENFUSION___STATICMAPOBJECT_H
#define ENFUSION___STATICMAPOBJECT_H

#include "../../../Engine/Core/Engine.h"

extern struct Tile;

class StaticMapObject {

public:
    StaticMapObject(string_t tileset, sf::IntRect texBounds);

    void setPosition(Tile&);
    virtual void render(sf::RenderWindow* window);

    inline void setTileset(string_t tileset)  { o_sprite.setTexture(AssetManager::Instance()->getTexture(tileset)); }
    inline void setBounds(sf::IntRect bounds) { o_sprite.setTextureRect(bounds); }

    inline sf::FloatRect bounds() { return o_sprite.getGlobalBounds(); }

private:
    sf::Sprite   o_sprite;
    sf::IntRect  o_bounds;

    Tile*        o_tile = nullptr;

};


#endif //ENFUSION___STATICMAPOBJECT_H
