#include "MapGenerator.h"

MapGenerator* MapGenerator::m_Instance = nullptr;


//TODO: Eventually use simplex noise for map generation to smooth transitions

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
        uint16_t biomeSize = rand()%(LEVEL_BIOME_SIZE_MAX-LEVEL_BIOME_SIZE_MIN + 1) + LEVEL_BIOME_SIZE_MIN;

        auto* biome = BiomeManager::Instance()->biome(rand()%(LEVEL_AMOUNT_BIOMES)+1);
        auto size = sf::Vector2i(biomeSize, biomeSize);
        if (pos.y+size.y > sizeY)
        {
            size.y = sizeY - pos.y;
            lastRun = true;
        }
        biome->generate(pos, size, map(), &m_staticObjects, sf::Vector2i(sizeX, sizeY));


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

    // Fill in empty sections
    // Temporary solution: set all tile biomes to that of last tile
    // causes weird biome strips in some areas
    pos.x = 0; pos.y = 0;
    for(uint32_t i = 0; i < (sizeX * sizeY); i++)
    {
        if (pos.x++ == sizeX)
        {
            pos.y++;
            pos.x = 0;
        }
        if (m_lvl[i].biome == LEVEL_BIOME_ID_NONE)
        {
            BiomeManager::Instance()->biome(m_lvl[i-1].biome)->createTransitionTile(&m_lvl[i], m_lvl[i-1].biome);
        }
    }

    //smooth transitions between terrains a bit
    pos.x = 0; pos.y = 0;
    for(uint32_t i = 0; i < (sizeX * sizeY); i++)
    {
        if (i == 0) continue;

        //check last X biome
        if (m_lvl[i-1].biome != m_lvl[i].biome)
        {
            //random value of two biomes
            uint8_t r = rand() % 2;
            if (r == 1)
                BiomeManager::Instance()->biome(m_lvl[i-1].biome)->createTransitionTile(&m_lvl[i], m_lvl[i-1].biome);
        }

        if ((int)i-sizeX >= 0)
        {
            if (m_lvl[i-sizeX].biome != m_lvl[i].biome)
            {
                uint8_t r = rand() % 2;
                if (r == 1)
                    BiomeManager::Instance()->biome(m_lvl[i-sizeX].biome)->createTransitionTile(&m_lvl[i], m_lvl[i-1].biome);
            }
        }
    }

    //set up texture tilemap
    for (uint32_t i = 0; i < (sizeX * sizeY); i++)
    {
        assert(m_lvl[i].biome != LEVEL_BIOME_ID_NONE);
        m_tilemap.push_back(m_lvl[i].tilesetID);
    }


    return tilemap();
}


