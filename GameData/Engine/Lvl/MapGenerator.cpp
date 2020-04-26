#include "MapGenerator.h"

//TODO: Develop Biome System for generation
//TODO: Once Done, spawn items like trees on
//TODO: Top absed on biome

MapGenerator* MapGenerator::m_Instance = nullptr;

MapGenerator* MapGenerator::Instance()
{
    if (m_Instance == nullptr)
        m_Instance = new MapGenerator();

    return m_Instance;
}

std::vector<int> MapGenerator::generateMap(uint16_t sizeX, uint16_t sizeY)
{
    //TODO: Generate Map Array Here
    //TODO: Determine biome sizes and boundaries? mathematical nightmare
    //TODO: Pass to biome classes once determined, have them return int array?
    //TODO: Feeling originally rather than an int, should be custom type
    m_lvl.clear();
    m_tilemap.clear();
    m_size.x = sizeX;
    m_size.y = sizeY;

    //set initial empty array
    for(uint32_t i = 0; i < (sizeX * sizeY); i++)
    {
        Tile t;
        t.tilesetID = 0;
        t.biome     = LEVEL_BIOME_ID_NONE;
        m_lvl.push_back(t);
    }

    //TODO: Split entire map into biomes
    //TODO: Loop left to right first and check for blanks?
    sf::Vector2i pos(0, 0);
    uint16_t largestBiomeHeight = 0;
    for(uint32_t i = 0; i >=0; i++)
    {
        uint16_t biomeSize = rand()%(LEVEL_BIOME_SIZE_MAX-LEVEL_BIOME_SIZE_MIN + 1) + LEVEL_BIOME_SIZE_MIN;;
        dbg_log(biomeSize)

        auto* biome = BiomeManager::Instance()->biome(rand()%(LEVEL_AMOUNT_BIOMES)+1);
        auto size = sf::Vector2i(biomeSize, biomeSize);
        if (pos.y+size.y > sizeY) break;
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
        pos.x += size.x;
    }

    for (uint32_t i = 0; i < (sizeX * sizeY); i++)
    {
        //TODO: Add below line once biomes are implemented
        //assert(m_lvl[i].biome != LEVEL_BIOME_ID_NONE);
        m_tilemap.push_back(m_lvl[i].tilesetID);
    }


    return tilemap();
}


