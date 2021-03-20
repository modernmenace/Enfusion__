#include "StaticMapObject.h"
#include "../../LvlStructs.h"
#include "../../MapGenerator.h"

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

    //todo: temporary blocking, whole sprite and mandatory
    //todo: next, find way to choose tiles to block by object
    sf::Rect<uint32_t> occTiles = resolvePositionRectToTileRect(o_sprite.getGlobalBounds());
    for(int i = 0; i < occTiles.width; i++)
        for(int j = 0; j < occTiles.height; j++)
            MapGenerator::Instance()->map()->m_tiles[occTiles.top + i + (j * 250)].blocked = true;

}

void StaticMapObject::render(sf::RenderWindow *window)
{
    window->draw(o_sprite);
}