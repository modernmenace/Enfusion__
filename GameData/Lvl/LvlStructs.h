#ifndef ENFUSION___LVLSTRUCTS_H
#define ENFUSION___LVLSTRUCTS_H

#include "../Engine/Core/Engine.h"
#include "Biomes/Objects/StaticMapObject.h"
#include <vector>

struct Tile
{
    uint16_t biome;
    uint16_t tilesetID;
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

#endif //ENFUSION___LVLSTRUCTS_H
