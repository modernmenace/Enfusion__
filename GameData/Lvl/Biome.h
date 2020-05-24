#ifndef ENFUSION___BIOME_H
#define ENFUSION___BIOME_H

#include "../Engine/Core/Engine.h"
#include "LvlStructs.h"
#include "Biomes/Objects/StaticMapObject.h"
#include <SFML/Graphics/RectangleShape.hpp>

#define LEVEL_BIOME_ID_NONE     0
#define LEVEL_BIOME_ID_WOODLAND 1
#define LEVEL_BIOME_ID_DESERT   2


class Biome
{

public:
    virtual void generate(sf::Vector2i position, sf::Vector2i area, std::vector<Tile>* map, sf::Vector2i mapArea) {};
    virtual void createTransitionTile(Tile* tile, uint16_t fromBiome)                                  {};
    virtual void initialize() {};

protected:
    std::vector<StaticMapObject> biome_staticMapObjects;
    std::vector<TileTexture>     biome_tileTextures;

    uint16_t randomTile()
    {
        float weightedSum = 0;
        for(uint16_t i = 0; i < biome_tileTextures.size(); i++)
            weightedSum += biome_tileTextures[i].weight;

        float weightedRand = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/weightedSum));

        for(uint16_t i = 0; i < biome_tileTextures.size(); i++)
        {
            if (weightedRand < biome_tileTextures[i].weight)
                return biome_tileTextures[i].tilesetID;
            else
                weightedRand -= biome_tileTextures[i].weight;
        }

        return biome_tileTextures[0].tilesetID;
    }

};


#endif //ENFUSION___BIOME_H
