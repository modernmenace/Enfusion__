#include "StaticMapObject.h"
#include "../../LvlStructs.h"
#include "../../MapGenerator.h"

//todo: how to block?
//todo: blocked tile array vs position rect

StaticMapObject::StaticMapObject(string_t tileset, sf::IntRect texBounds) : o_sprite()
{
    o_sprite.setTexture(AssetManager::Instance()->getTexture(tileset));
    o_bounds = texBounds;
    o_sprite.setScale(GLOBAL_SCALE_GAMEOBJECT);
    o_sprite.setTextureRect(o_bounds);

}

//todo: update blocking here
void StaticMapObject::setPosition(Tile& tile)
{
    o_tile = &tile;
    o_sprite.setPosition(o_tile->position);

    //todo: temporary blocking, whole sprite and mandatory
    sf::Rect<uint32_t> occTiles = resolvePositionRectToTileRect(o_sprite.getGlobalBounds());
    for(int i = 0; i < occTiles.width; i++)
        MapGenerator::Instance()->map()->m_tiles[occTiles.left + i].blocked = true;
    for(int i = 0; i < occTiles.width; i++)
        MapGenerator::Instance()->map()->m_tiles[occTiles.top + (i * 250)].blocked = true;

}



void StaticMapObject::render(sf::RenderWindow *window)
{
    window->draw(o_sprite);
}