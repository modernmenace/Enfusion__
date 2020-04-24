#ifndef ENFUSION___BIOME_DESERT_H
#define ENFUSION___BIOME_DESERT_H

#include "../Biome.h"

class Biome_Desert : Biome
{
public:
    void generate(sf::RectangleShape area, std::vector<Tile>* map) override
    {
        //TODO: Generate Woodland Biome
        dbg_log("Generating Desert Biome")


    }
};


#endif //ENFUSION___BIOME_DESERT_H
