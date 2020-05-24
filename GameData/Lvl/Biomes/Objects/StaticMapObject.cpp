#include "StaticMapObject.h"

StaticMapObject::StaticMapObject(string_t tileset, sf::IntRect texBounds)
{
    o_sprite.setTexture(AssetManager::Instance()->getTexture(tileset));
    o_bounds = texBounds;
}

void StaticMapObject::render(sf::RenderWindow *window)
{

}