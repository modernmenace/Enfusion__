#ifndef ENFUSION___BIOME_DESERT_H
#define ENFUSION___BIOME_DESERT_H

#include "../Biome.h"


class Biome_Desert : public Biome
{
public:
    void generate(sf::Vector2i, sf::Vector2i, std::vector<Tile>*, sf::Vector2i) override;

    void createTransitionTile(Tile* tile, uint16_t fromBiome) override
    {
        tile->tilesetID = getWeightedRandomTile();
        tile->biome = LEVEL_BIOME_ID_DESERT;
    }

private:
    struct Tile_Texture
    {
        uint16_t tilesetID;
        float tileWeight;
    };

    const static uint16_t tileTextures = 15;
    const Tile_Texture tiles[tileTextures] =
            {
                {352,  1},
                {353,  1},
                {354,  1},
                {355,  1},
                {356,  1},
                {357,  1},
                {358,  1},
                {361,  0.01},
                {362,  0.01},
                {363,  0.01},
                {364,  0.01},
                {365,  0.01},
                {366,  0.01},
                {367,  0.01},
                {368,  0.01}
            };

    uint16_t getWeightedRandomTile();
};


#endif //ENFUSION___BIOME_DESERT_H
