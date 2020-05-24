#ifndef ENFUSION___LVLSTRUCTS_H
#define ENFUSION___LVLSTRUCTS_H

#include <stdint.h>
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
    uint8_t width;
    uint8_t height;
    std::vector<uint16_t> tiles;
};

#endif //ENFUSION___LVLSTRUCTS_H
