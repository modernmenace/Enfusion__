#ifndef ENFUSION___BIOME_DESERT_H
#define ENFUSION___BIOME_DESERT_H

#include "../Biome.h"


class Biome_Desert : public Biome
{
public:
    void generate(sf::Vector2i, sf::Vector2i, std::vector<Tile>*, sf::Vector2i) override;

    void createTransitionTile(Tile* tile, uint16_t fromBiome) override
    {
        //TODO: implement fromBiome
        //choose random from tileset (352-358 for now)
        tile->tilesetID = rand()%(358-352 + 1) + 352;
        tile->biome = LEVEL_BIOME_ID_DESERT;
    }

private:
    struct Tile_Texture
    {
        uint16_t tilesetID;
        float tileWeight;
    };

    const static uint16_t tileTextures = 7;
    const Tile_Texture tiles[tileTextures] =
            {
                {352,  1},
                {353,  1},
                {354,  1},
                {355,  1},
                {356,  1},
                {357,  1},
                {358,  1}
            };

    uint16_t getWeightedRandomTile();
};


#endif //ENFUSION___BIOME_DESERT_H
