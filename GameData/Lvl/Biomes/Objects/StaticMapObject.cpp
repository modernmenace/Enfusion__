#include "StaticMapObject.h"
#include "../../LvlStructs.h"

//todo: how to block?
//todo: blocked tile array vs position rect

StaticMapObject::StaticMapObject(string_t tileset, sf::IntRect texBounds) : o_sprite()
{
    o_sprite.setTexture(AssetManager::Instance()->getTexture(tileset));
    o_bounds = texBounds;
    o_sprite.setScale(GLOBAL_SCALE_GAMEOBJECT);
    o_sprite.setTextureRect(o_bounds);

}

void StaticMapObject::setPosition(Tile& tile)
{
    o_tile = &tile;
    o_sprite.setPosition(o_tile->position);
}



void StaticMapObject::render(sf::RenderWindow *window)
{
    window->draw(o_sprite);
}