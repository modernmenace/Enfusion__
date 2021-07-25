#ifndef ENFUSION___BIOME_DESERT_H
#define ENFUSION___BIOME_DESERT_H

#include "../Biome.h"


class Biome_Desert : public Biome
{
public:
    void generate(sf::Vector2i, sf::Vector2i, std::vector<Tile>*, sf::Vector2i) override;
    void initialize() override;

    void createTransitionTile(Tile* tile, uint16_t fromBiome) override
    {
        tile->tilesetID = randomTile();
        tile->tileSize  = 16 * GLOBAL_SCALE_TILE.x;
        tile->biome     = LEVEL_BIOME_ID_DESERT;
        tile->blocked   = false;
    }

};


#endif //ENFUSION___BIOME_DESERT_H
