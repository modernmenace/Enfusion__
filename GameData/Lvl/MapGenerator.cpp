#include "MapGenerator.h"
#include "Biomes/Objects/Desert/Cactus.h"
#include "Biomes/Objects/Desert/Cactus2.h"
#include "Biomes/Objects/Desert/DeadTree.h"
#include "../Engine/Lvl/LevelManager.h"

MapGenerator* MapGenerator::m_Instance = nullptr;

//TODO: Eventually use simplex noise for map generation to smooth transitions

/************************************************************************
 * FUNCTION :       MapGenerator::MapGenerator
 *
 * DESCRIPTION :
 *       Constructor
 *
 *  INPUTS:  NONE
 *
 *  OUTPUTS: NONE
 *
 *  VERSION   	DATE    		WHO     DETAIL
 *  V1.00.00   	2020.11.26 	    JCB     Documentation Start
 *
 ************************************************************************/

MapGenerator::MapGenerator()
{
    populateBiomeObjects();
}

/************************************************************************
 * FUNCTION :       MapGenerator::Instance
 *
 * DESCRIPTION :
 *       Fetch the singleton instance of the map generator
 *
 *  INPUTS:  NONE
 *
 *  OUTPUTS: MapGenerator* : instance
 *
 *  VERSION   	DATE    		WHO     DETAIL
 *  V1.00.00   	2020.11.26 	    JCB     Documentation Start
 *
 ************************************************************************/

MapGenerator* MapGenerator::Instance()
{
    if (m_Instance == nullptr)
        m_Instance = new MapGenerator();

    return m_Instance;
}

/************************************************************************
 * FUNCTION :       MapGenerator::populateBiomeObjects
 *
 * DESCRIPTION :
 *       Set up biome object types for the generator
 *
 *  INPUTS:  NONE
 *
 *  OUTPUTS: NONE
 *
 *  VERSION   	DATE    		WHO     DETAIL
 *  V1.00.00   	2020.11.26 	    JCB     Documentation Start
 *
 ************************************************************************/

void MapGenerator::populateBiomeObjects()
{
    m_biomeObjects[LEVEL_BIOME_ID_DESERT].push_back({Cactus(), 1});
    m_biomeObjects[LEVEL_BIOME_ID_DESERT].push_back({Cactus2(), 1});
    m_biomeObjects[LEVEL_BIOME_ID_DESERT].push_back({DeadTree(), 0.5});
}

/************************************************************************
 * FUNCTION :       MapGenerator::getRandomObject
 *
 * DESCRIPTION :
 *       Returns a random weighted object by biome type
 *
 *  INPUTS:  uint16_t biomeID : Biome type of object
 *
 *  OUTPUTS: StaticMapObject* : return address of the object
 *
 *  VERSION   	DATE    		WHO     DETAIL
 *  V1.00.00   	2020.11.26 	    JCB     Documentation Start
 *
 ************************************************************************/

StaticMapObject* MapGenerator::getRandomObject(uint16_t biomeID)
{
    auto& vec = m_biomeObjects[biomeID];
    if (vec.size() == 0)
        return nullptr;

    float weightedSum = 0;
    for(uint16_t i = 0; i < vec.size(); i++)
        weightedSum += vec[i].weight;

    float weightedRand = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/weightedSum));

    for(uint16_t i = 0; i < vec.size(); i++)
    {
        if (weightedRand < vec[i].weight)
            return &vec[i].obj;
        else
            weightedRand -= vec[i].weight;
    }

    return &vec[0].obj;
}

/************************************************************************
 * FUNCTION :       MapGenerator::generateMap
 *
 * DESCRIPTION :
 *       Generate and populate the map
 *
 *  INPUTS:  uint16_t sizeX    : X-size of the map
 *           uint16_t sizeY    : Y-size of the map
 *           uint16_t tileSize : Size of individual tiles
 *
 *  OUTPUTS: NONE
 *
 *  VERSION   	DATE    		WHO     DETAIL
 *  V1.00.00   	2020.11.26 	    JCB     Documentation Start
 *
 ************************************************************************/

Map* MapGenerator::generateMap(uint16_t sizeX, uint16_t sizeY, uint16_t tileSize)
{
    assert(m_map == nullptr);
    m_lvl.clear();
    m_size.x = sizeX;
    m_size.y = sizeY;
    m_tileSize = tileSize;
    std::vector<StaticMapObject*> m_staticObjects;

    m_boundaries.x = m_size.x * tileSize * GLOBAL_SCALE_TILE.x; //scaled by 2 in tilemap.cpp
    m_boundaries.y = m_size.y * tileSize * GLOBAL_SCALE_TILE.y; //scaled by 2 in tilemap.cpp
    LevelManager::Instance()->setBoundaries(m_boundaries);

    //set initial empty map array
    for(uint32_t i = 0; i < (sizeX * sizeY); i++)
    {
        //if issue pops up here, arrayPos and tileSize
        //may need to be initialized in transition tiles
        Tile t;
        t.tilesetID = 0;
        t.biome     = LEVEL_BIOME_ID_NONE;
        t.blocked   = false;
        t.tileSize  = tileSize * GLOBAL_SCALE_TILE.x;
        t.arrayPos  = i;
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
        biome->generate(pos, size, &m_lvl, &m_staticObjects, sf::Vector2i(sizeX, sizeY));


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
            sf::Vector2f tempPos;
            tempPos.x = pos.x * 32;
            tempPos.y = pos.y * 32;
            BiomeManager::Instance()->biome(m_lvl[i-1].biome)->createTransitionTile(&m_lvl[i], tempPos, m_lvl[i-1].biome);
        }
    }

    uint16_t numTiles[LEVEL_AMOUNT_BIOMES+1];
    //smooth transitions between terrains a bit
    pos.x = 0; pos.y = 0;
    for(uint32_t i = 0; i < (sizeX * sizeY); i++)
    {
        if (i == 0) continue;

        if (pos.x++ == sizeX)
        {
            pos.y++;
            pos.x = 0;
        }

        //check last X biome
        if (m_lvl[i-1].biome != m_lvl[i].biome)
        {
            //random value of two biomes
            uint8_t r = rand() % 2;
            if (r == 1)
            {
                sf::Vector2f tempPos;
                tempPos.x = pos.x * 32;
                tempPos.y = pos.y * 32;
                BiomeManager::Instance()->biome(m_lvl[i-1].biome)->createTransitionTile(&m_lvl[i], tempPos, m_lvl[i-1].biome);
            }
        }

        if ((int)i-sizeX >= 0)
        {
            if (m_lvl[i-sizeX].biome != m_lvl[i].biome)
            {
                uint8_t r = rand() % 2;
                if (r == 1)
                {
                    sf::Vector2f tempPos;
                    tempPos.x = pos.x * 32;
                    tempPos.y = pos.y * 32;
                    BiomeManager::Instance()->biome(m_lvl[i-sizeX].biome)->createTransitionTile(&m_lvl[i], tempPos, m_lvl[i-1].biome);
                }
            }
        }
        numTiles[m_lvl[i].biome]++;
    }

    //generate static objects
    for(uint32_t i = 0; i < (m_size.x * m_size.y); i++)
    {
        bool place = (rand() % 100) < MAPGEN_CHANCE_STATICOBJECT;
        if (!place) continue;
        //why is this r here and why does removing it crash program?
        StaticMapObject* r = getRandomObject(m_lvl[i].biome);
        if (r == nullptr) continue;

        StaticMapObject* obj = new StaticMapObject(*getRandomObject(m_lvl[i].biome));
        obj->setPosition(m_lvl[i]);
        m_staticObjects.push_back(obj);
    }

    m_map = new Map;
    m_map->m_tiles      = m_lvl;
    m_map->m_mapObjects = m_staticObjects;

    return m_map;
}
