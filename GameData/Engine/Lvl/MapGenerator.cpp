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
        t.biome     = 0;
        m_lvl.push_back(t);
    }

    //biome stuff, have biomes edit array

    for (uint32_t i = 0; i < (sizeX * sizeY); i++) m_tilemap.push_back(m_lvl[i].tilesetID);


    return tilemap();
}


