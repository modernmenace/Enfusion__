#ifndef ENFUSION___BIOME_H
#define ENFUSION___BIOME_H

#include "../Engine/Core/Engine.h"
#include <SFML/Graphics/RectangleShape.hpp>

#define LEVEL_BIOME_ID_NONE     0
#define LEVEL_BIOME_ID_WOODLAND 1
#define LEVEL_BIOME_ID_DESERT   2

struct Tile
{
    uint16_t biome;
    uint16_t tilesetID;
};

struct TileWeight
{
    uint16_t tilesetID;
    uint8_t weight;
};

class Biome
{

public:
    virtual void generate(sf::Vector2i position, sf::Vector2i area, std::vector<Tile>* map, sf::Vector2i mapArea) {};
    virtual void createTransitionTile(Tile* tile, uint16_t fromBiome)                                  {};
};


#endif //ENFUSION___BIOME_H
