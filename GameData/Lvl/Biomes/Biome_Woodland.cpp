#include "Biome_Woodland.h"

void Biome_Woodland::generate(sf::Vector2i position, sf::Vector2i area, std::vector<Tile> *map, std::vector<StaticMapObject*>* objs, sf::Vector2i mapArea)
{
    //generate ground tile
    auto nPos = position;
    for(uint16_t j = 0; j < area.y; j++)
    {
        for(uint16_t i = 0; i < area.x; i++)
        {
            if ((nPos.y+nPos.x) < (nPos.y + mapArea.x))
            {
                Tile* t = &map->at((nPos.y * mapArea.x)+nPos.x);
                t->tilesetID = randomTile();
                t->biome = LEVEL_BIOME_ID_WOODLAND;
                nPos.x++;
            }
        }
        nPos.x = position.x;
        nPos.y++;
    }
}

void Biome_Woodland::initialize()
{
    biome_tileTextures.push_back({41,  1});
    biome_tileTextures.push_back({42,  1});
    biome_tileTextures.push_back({43,  1});
}