#ifndef ENFUSION___BIOME_WOODLAND_H
#define ENFUSION___BIOME_WOODLAND_H

#include "../Biome.h"

class Biome_Woodland : public Biome
{

public:
    void generate(sf::Vector2i position, sf::Vector2i area, std::vector<Tile>* map) override
    {
        //TODO: Generate Woodland Biome
        dbg_log("Generating Woodland Biome")

        //ground texture
        map->at(0).tilesetID = 69;

    }

};


#endif //ENFUSION___BIOME_WOODLAND_H
