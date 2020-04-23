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
    lvl.clear();
    m_size.x = sizeX;
    m_size.y = sizeY;
    for (int i = 0; i < (sizeX * sizeY); i++)
        lvl.push_back(70);


    return lvl;
}


