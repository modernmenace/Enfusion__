#include "StaticMapObject.h"
#include "../../LvlStructs.h"

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
    dbg_log(o_tile->tileSize)
    o_sprite.setPosition(o_tile->position);
}



void StaticMapObject::render(sf::RenderWindow *window)
{
    window->draw(o_sprite);
}