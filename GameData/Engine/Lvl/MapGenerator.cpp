#include "MapGenerator.h"

MapGenerator* MapGenerator::m_Instance = nullptr;

//TODO: Why is this crashing? no logical reason

MapGenerator::MapGenerator()
{
    for (int i = 0; i < (12 * 9); i++)
        lvl.push_back(70);
}

MapGenerator* MapGenerator::Instance()
{
    if (m_Instance == nullptr)
        m_Instance = new MapGenerator();

    return m_Instance;
}


std::vector<int> MapGenerator::generateMap(uint16_t sizeX, uint16_t sizeY)
{
    //TODO: Generate Map Array Here
    return lvl;
}


