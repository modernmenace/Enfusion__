#ifndef ENFUSION___BIOME_WOODLAND_H
#define ENFUSION___BIOME_WOODLAND_H

#include "../Biome.h"

class Biome_Woodland : public Biome
{

public:
    void generate(sf::Vector2i position, sf::Vector2i area, std::vector<Tile>* map, std::vector<StaticMapObject*>*, sf::Vector2i mapArea) override;
    void initialize() override;

    void createTransitionTile(Tile* tile, uint16_t fromBiome) override
    {
        tile->tilesetID = randomTile();
        tile->biome = LEVEL_BIOME_ID_WOODLAND;
    }

};


#endif //ENFUSION___BIOME_WOODLAND_H
