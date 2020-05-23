#include "Biome_Desert.h"

void Biome_Desert::generate(sf::Vector2i position, sf::Vector2i area, std::vector<Tile> *map, sf::Vector2i mapArea)
{
    //generate ground tile
    auto nPos = position;
    for(uint16_t j = 0; j < area.y; j++)
    {
        for(uint16_t i = 0; i < area.x; i++)
        {
            if ((nPos.y+nPos.x) < (nPos.y + mapArea.x))
            {
                Tile* t = &map->at((nPos.y * mapArea.x)+nPos.x);
                //todo: use tiles for weight and id
                t->tilesetID = getWeightedRandomTile();
                t->biome = LEVEL_BIOME_ID_DESERT;
                nPos.x++;
            }
        }
        nPos.x = position.x;
        nPos.y++;
    }
}

uint16_t Biome_Desert::getWeightedRandomTile()
{
    float weightedSum = 0;
    for(uint16_t i = 0; i < tileTextures; i++)
        weightedSum += tiles[i].tileWeight;

    float weightedRand = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/weightedSum));

    for(uint16_t i = 0; i < tileTextures; i++)
    {
        if (weightedRand < tiles[i].tileWeight)
            return tiles[i].tilesetID;
        else
            weightedRand -= tiles[i].tileWeight;
    }

    return tiles[0].tilesetID;
}