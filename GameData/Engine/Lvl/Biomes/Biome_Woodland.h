#ifndef ENFUSION___BIOME_WOODLAND_H
#define ENFUSION___BIOME_WOODLAND_H

#include "../Biome.h"

class Biome_Woodland : public Biome
{

public:
    void generate(sf::Vector2i position, sf::Vector2i area, std::vector<Tile>* map, sf::Vector2i mapArea) override
    {
        dbg_log("Generating Woodland Biome")

        //generate ground tile
        auto nPos = position;
        for(uint16_t j = 0; j < area.y; j++)
        {
            //row loop
            for(uint16_t i = 0; i < area.x; i++)
            {
                if ((nPos.y+nPos.x) < (nPos.y + mapArea.x))
                {
                    Tile* t = &map->at((nPos.y * mapArea.x)+nPos.x);
                    t->tilesetID = 69;
                    nPos.x++;
                }
            }
            nPos.x = position.x;
            nPos.y++;
        }
    }

};


#endif //ENFUSION___BIOME_WOODLAND_H
