#ifndef ENFUSION___LVLSTRUCTS_H
#define ENFUSION___LVLSTRUCTS_H

#include "../Engine/Core/Engine.h"
#include "Biomes/Objects/StaticMapObject.h"
#include <vector>
#include <cmath>

struct Tile
{
    uint16_t     biome;
    uint16_t     tilesetID;
    uint16_t     tileSize;
    sf::Vector2f position;
    uint32_t     arrayPos;
    bool         blocked;
};

struct TileTexture
{
    uint16_t tilesetID;
    float    weight;
};

struct WeightedMapObject
{
    StaticMapObject obj;
    float weight;
};

struct Map
{
    std::vector<StaticMapObject*> m_mapObjects;
    std::vector<Tile>             m_tiles;
};

//todo: magic numbers!
inline static uint32_t resolvePositionToTile(uint16_t x, uint16_t y)
{
    return ((y / 32) * 250)+(x / 32); //250 is map sizeX
}

inline static uint32_t resolvePositionToTile(sf::Vector2f position)
{
    resolvePositionToTile(position.x, position.y);
}

//todo: magic numbers!
static sf::Rect<uint32_t> resolvePositionRectToTileRect(sf::Rect<float> rect)
{
    sf::Rect<uint32_t> ret;
    ret.left   = resolvePositionToTile(rect.left, rect.top);
    ret.top    = ret.left;
    ret.width  = resolvePositionToTile(rect.left + rect.width, rect.top) - ret.left;
    ret.height = (resolvePositionToTile(rect.left, rect.top + rect.height) / 250)
                 - (ret.left / 250);
    return ret;
}

//todo: magic numbers!
inline static sf::Vector2u resolveTileToPosition(uint16_t arrayPos)
{
    return sf::Vector2u((arrayPos % 250) * 32, (32 * (arrayPos / 250)));
}

static sf::Vector2i resolveTileDistance(Tile* t1, Tile* t2)
{
    sf::Vector2i ret;
    ret.x = abs(t2->position.x - t1->position.x);
    ret.y = abs(t2->position.y - t1->position.y);
    return ret;
}

#endif //ENFUSION___LVLSTRUCTS_H
