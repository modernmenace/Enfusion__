#ifndef ENFUSION___BIOME_DESERT_H
#define ENFUSION___BIOME_DESERT_H

#include "../Biome.h"

class Biome_Desert : public Biome
{
public:
    void generate(sf::Vector2i position, sf::Vector2i area, std::vector<Tile>* map, sf::Vector2i mapArea) override
    {
        dbg_log("Generating Desert Biome")

        //generate ground tile
        auto nPos = position;
        for(uint16_t j = 0; j < area.y; j++)
        {
            for(uint16_t i = 0; i < area.x; i++)
            {
                if ((nPos.y+nPos.x) < (nPos.y + mapArea.x))
                {
                    Tile* t = &map->at((nPos.y * mapArea.x)+nPos.x);
                    t->tilesetID = 5;
                    t->biome = LEVEL_BIOME_ID_DESERT;
                    nPos.x++;
                }
            }
            nPos.x = position.x;
            nPos.y++;
        }
    }

    void createTransitionTile(sf::Vector2i position, uint16_t fromBiome) override
    {
        //TODO: Implement This
    }

};


#endif //ENFUSION___BIOME_DESERT_H
