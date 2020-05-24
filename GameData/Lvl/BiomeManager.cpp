#include "BiomeManager.h"
#include "Biomes/Biome_Woodland.h"
#include "Biomes/Biome_Desert.h"

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
    biomes[LEVEL_BIOME_ID_DESERT]   = new Biome_Desert();

    for(int i = 1; i < LEVEL_AMOUNT_BIOMES+1; i++)
        biomes[i]->initialize();
}

BiomeManager::~BiomeManager()
{
    for(Biome* b : biomes)
        delete b;
}



