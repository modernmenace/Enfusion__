#include "MapGenerator.h"

MapGenerator* MapGenerator::m_Instance = nullptr;

MapGenerator* MapGenerator::Instance()
{
    if (m_Instance == nullptr)
        m_Instance = new MapGenerator();

    return m_Instance;
}

std::vector<int> MapGenerator::generateMap(uint16_t sizeX, uint16_t sizeY)
{
    m_lvl.clear();
    m_tilemap.clear();
    m_size.x = sizeX;
    m_size.y = sizeY;

    //set initial empty map array
    for(uint32_t i = 0; i < (sizeX * sizeY); i++)
    {
        Tile t;
        t.tilesetID = 0;
        t.biome     = LEVEL_BIOME_ID_NONE;
        m_lvl.push_back(t);
    }


    sf::Vector2i pos(0, 0);
    uint16_t largestBiomeHeight = 0;
    bool lastRun = false;

    //run through map and place majority of biomes
    //still large empty sections after this
    for(uint32_t i = 0; i >=0; i++)
    {
        if (lastRun) break;
        uint16_t biomeSize = rand()%(LEVEL_BIOME_SIZE_MAX-LEVEL_BIOME_SIZE_MIN + 1) + LEVEL_BIOME_SIZE_MIN;;
        dbg_log(biomeSize)

        auto* biome = BiomeManager::Instance()->biome(rand()%(LEVEL_AMOUNT_BIOMES)+1);
        auto size = sf::Vector2i(biomeSize, biomeSize);
        if (pos.y+size.y > sizeY)
        {
            size.y = sizeY - pos.y;
            lastRun = true;
        }
        biome->generate(pos, size, map(), sf::Vector2i(sizeX, sizeY));


        if ((pos.x + size.x) > (sizeX))
        {
            if (size.y > largestBiomeHeight)
                largestBiomeHeight = size.y;
            pos.y += size.y;
            pos.x = 0;
            if (pos.y == sizeY)
                break;
        }
        else
            pos.x += size.x;
    }

    //TODO: loop - Fill in empty sections



    //TODO: loop - smooth transitions between terrains

    //set up texture tilemap
    for (uint32_t i = 0; i < (sizeX * sizeY); i++)
    {
        //TODO: Add below line once biomes are implemented
        //assert(m_lvl[i].biome != LEVEL_BIOME_ID_NONE);
        m_tilemap.push_back(m_lvl[i].tilesetID);
    }


    return tilemap();
}


