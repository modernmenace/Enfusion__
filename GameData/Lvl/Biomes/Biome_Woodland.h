#ifndef ENFUSION___BIOME_WOODLAND_H
#define ENFUSION___BIOME_WOODLAND_H

#include "../Biome.h"

class Biome_Woodland : public Biome
{

public:
    void generate(sf::Vector2i position, sf::Vector2i area, std::vector<Tile>* map, sf::Vector2i mapArea) override
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
                    t->tilesetID = 42;
                    t->biome = LEVEL_BIOME_ID_WOODLAND;
                    nPos.x++;
                }
            }
            nPos.x = position.x;
            nPos.y++;
        }
    }

    void createTransitionTile(Tile* tile, uint16_t fromBiome) override
    {
        //TODO: implement fromBiome
        tile->tilesetID = 42;
        tile->biome = LEVEL_BIOME_ID_WOODLAND;
    }

};


#endif //ENFUSION___BIOME_WOODLAND_H
