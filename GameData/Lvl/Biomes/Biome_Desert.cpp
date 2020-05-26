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
                nPos.x++;
            }
        }
        nPos.x = position.x;
        nPos.y++;
    }

    //TODO: 1) determine amount of objects to place
    //TODO: min and max hard coded and not based on size
    uint16_t maxObjects = 20;
    uint16_t minObjects = 10;
    uint16_t objectCount = rand() % ((maxObjects - minObjects) + 1) + minObjects;

    //TODO: 2) determine weighted object to place


    //TODO: 3) pick random position for object
    //TODO: not accountng for transition tiles
    for(uint16_t j = 0; j < objectCount; j++)
    {
        uint16_t randX = rand() % (((position.x + area.x) - position.x) + 1) + position.x;
        uint16_t randY = rand() % (((position.y + area.y) - position.y) + 1) + position.y;
        objs->push_back(new Cactus(sf::Vector2f(randX * 16 * 2, randY * 16 * 2)));
        dbg_log("Random Object Placed at " << randX << ", " << randY << " based on bounds " << position.x << ", " << position.y << ", " << area.x << ", " << area.y)
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