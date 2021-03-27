#include "StaticMapObject.h"
#include "../../LvlStructs.h"
#include "../../MapGenerator.h"

StaticMapObject::StaticMapObject(string_t tileset, sf::IntRect texBounds) : o_sprite()
{
    o_sprite.setTexture(AssetManager::Instance()->getTexture(tileset));
    o_bounds = texBounds;
    o_sprite.setScale(GLOBAL_SCALE_GAMEOBJECT);
    o_sprite.setTextureRect(o_bounds);
    o_tileWidth  = (o_sprite.getGlobalBounds().width / 32)  + 1;
    o_tileHeight = (o_sprite.getGlobalBounds().height / 32) + 1;
}

void StaticMapObject::setPosition(Tile& tile)
{
    o_tile = &tile;
    o_sprite.setPosition(o_tile->position);
    sf::Rect<uint32_t> occTiles = resolvePositionRectToTileRect(o_sprite.getGlobalBounds());

    //below code for blocking whole sprite
    /*
    for(int i = 0; i < occTiles.width; i++)
    {
        for(int j = 0; j < occTiles.height; j++)
        {
            uint32_t arrayPos = occTiles.top + i + (j * 250);
            if (arrayPos > MapGenerator::Instance()->map()->m_tiles.size())
                continue;
            MapGenerator::Instance()->map()->m_tiles[arrayPos].blocked = true;
        }
    }
     */
    o_tiles = occTiles;
}

void StaticMapObject::render(sf::RenderWindow *window)
{
    window->draw(o_sprite);
}