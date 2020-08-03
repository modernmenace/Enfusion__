#ifndef ENFUSION___BIOME_DESERT_H
#define ENFUSION___BIOME_DESERT_H

#include "../Biome.h"


class Biome_Desert : public Biome
{
public:
    void generate(sf::Vector2i, sf::Vector2i, std::vector<Tile>*, std::vector<StaticMapObject*>*, sf::Vector2i) override;
    void initialize() override;

    void createTransitionTile(Tile* tile, sf::Vector2f position, uint16_t fromBiome) override
    {
        tile->tilesetID = randomTile();
        tile->position  = position;
        tile->biome = LEVEL_BIOME_ID_DESERT;
    }

};


#endif //ENFUSION___BIOME_DESERT_H
