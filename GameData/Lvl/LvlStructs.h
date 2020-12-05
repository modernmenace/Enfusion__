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

static uint32_t resolvePositionToTile(uint16_t x, uint16_t y)
{
    uint16_t px = ceil(x);
    uint16_t py = ceil(y);
    return ((py / 32) * 250)+(px / 32); //250 is map sizeX
}

#endif //ENFUSION___LVLSTRUCTS_H
