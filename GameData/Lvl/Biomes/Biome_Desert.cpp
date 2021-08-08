#include "Biome_Desert.h"
#include <cmath>

void Biome_Desert::generate(sf::Vector2i position, sf::Vector2i area, std::vector<Tile> *map, sf::Vector2i mapArea)
{
    //generate ground tiles
    auto nPos = position;
    for(uint16_t j = 0; j < area.y; j++)
    {
        for(uint16_t i = 0; i < area.x; i++)
        {
            if ((nPos.y+nPos.x) < (nPos.y + mapArea.x))
            {
                uint16_t px = ceil(nPos.x);
                uint16_t py = ceil(nPos.y);
                Tile* t = &map->at((py * mapArea.x)+px);
                t->tilesetID = randomTile();
                t->biome = LEVEL_BIOME_ID_DESERT;
                nPos.x++;
            }
        }
        nPos.x = position.x;
        nPos.y++;
    }
}

void Biome_Desert::initialize()
{
    biome_tileTextures.push_back({352,  1});
    biome_tileTextures.push_back({353,  1});
    biome_tileTextures.push_back({354,  1});
    biome_tileTextures.push_back({355,  1});
    biome_tileTextures.push_back({356,  1});
    biome_tileTextures.push_back({357,  1});
    biome_tileTextures.push_back({361,  0.01});
    biome_tileTextures.push_back({362,  0.01});
    biome_tileTextures.push_back({363,  0.01});
    biome_tileTextures.push_back({364,  0.01});
    biome_tileTextures.push_back({365,  0.01});
    biome_tileTextures.push_back({366,  0.01});
    biome_tileTextures.push_back({367,  0.01});
    biome_tileTextures.push_back({368,  0.01});
}