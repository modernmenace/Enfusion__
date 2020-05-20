#include "Biome_Desert.h"

void Biome_Desert::generate(sf::Vector2i position, sf::Vector2i area, std::vector<Tile> *map, sf::Vector2i mapArea)
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
                //choose random from tileset (352-358 for now)
                t->tilesetID = rand()%(358-352 + 1) + 352;
                t->biome = LEVEL_BIOME_ID_DESERT;
                nPos.x++;
            }
        }
        nPos.x = position.x;
        nPos.y++;
    }
}