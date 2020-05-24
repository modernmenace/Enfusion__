#ifndef ENFUSION___LVLSTRUCTS_H
#define ENFUSION___LVLSTRUCTS_H

#include "../Engine/Core/Engine.h"
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

struct StaticMapObject
{
    sf::Sprite  obj;
    sf::IntRect location;
    bool        blocked = false;
};

#endif //ENFUSION___LVLSTRUCTS_H
