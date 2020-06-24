#include "Biome_Desert.h"
#include "Objects/Desert/Cactus.h"

void Biome_Desert::generate(sf::Vector2i position, sf::Vector2i area, std::vector<Tile> *map, std::vector<StaticMapObject*>* objs, sf::Vector2i mapArea)
{
    //generate ground tiles
    auto nPos = position;
    for(uint16_t j = 0; j < area.y; j++)
    {
        for(uint16_t i = 0; i < area.x; i++)
        {
            if ((nPos.y+nPos.x) < (nPos.y + mapArea.x))
            {
                Tile* t = &map->at((nPos.y * mapArea.x)+nPos.x);
                t->tilesetID = randomTile();
                t->biome = LEVEL_BIOME_ID_DESERT;
                //todo: using magic number here, fix
                //todo: 32 = tileSize (16) * transform scale (2)
                t->position.x = (nPos.x * 32);
                t->position.y = (nPos.y * 32);
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