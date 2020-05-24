#ifndef ENFUSION___STATICMAPOBJECT_H
#define ENFUSION___STATICMAPOBJECT_H

#include "../../../Engine/Core/Engine.h"

class StaticMapObject {

public:
    StaticMapObject(string_t tileset, sf::IntRect texBounds);

    virtual void initialize() {};
    virtual void render(sf::RenderWindow* window);

    inline void setTileset(string_t tileset)  { o_sprite.setTexture(AssetManager::Instance()->getTexture(tileset)); }
    inline void setBounds(sf::IntRect bounds) { o_sprite.setTextureRect(bounds); }

private:
    sf::Sprite  o_sprite;
    sf::IntRect o_bounds;

};


#endif //ENFUSION___STATICMAPOBJECT_H
