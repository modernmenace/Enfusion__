#include "StaticMapObject.h"

StaticMapObject::StaticMapObject(string_t tileset, sf::IntRect texBounds)
{
    o_sprite.setTexture(AssetManager::Instance()->getTexture(tileset));
    o_bounds = texBounds;
    o_sprite.setTextureRect(o_bounds);

    o_sprite.setPosition(0, 0); //for now
}

void StaticMapObject::render(sf::RenderWindow *window)
{
    window->draw(o_sprite);
}