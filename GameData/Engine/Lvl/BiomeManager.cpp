#include "BiomeManager.h"
#include "Biomes/Biome_Woodland.h"

BiomeManager* BiomeManager::m_Instance = nullptr;

//TODO: This singleton class will store info on individual biomes

BiomeManager* BiomeManager::Instance()
{
    if (m_Instance == nullptr)
        m_Instance = new BiomeManager();

    return m_Instance;
}

BiomeManager::BiomeManager()
{
    biomes[LEVEL_BIOME_ID_WOODLAND] = new Biome_Woodland();
}

BiomeManager::~BiomeManager()
{
    for(Biome* b : biomes)
        delete b;
}



