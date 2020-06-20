#include "MapGenerator.h"
#include "Biomes/Objects/Desert/Cactus.h"

MapGenerator* MapGenerator::m_Instance = nullptr;


//TODO: Eventually use simplex noise for map generation to smooth transitions

MapGenerator::MapGenerator()
{
    populateBiomeObjects();
}

MapGenerator::~MapGenerator()
{
    for(uint32_t i = 0; i < m_staticObjects.size(); i++)
        delete m_staticObjects[i];
}

MapGenerator* MapGenerator::Instance()
{
    if (m_Instance == nullptr)
        m_Instance = new MapGenerator();

    return m_Instance;
}

void MapGenerator::populateBiomeObjects()
{
    m_biomeObjects[LEVEL_BIOME_ID_DESERT].push_back({Cactus(sf::Vector2f(0,0)), 1});
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

    uint16_t numTiles[LEVEL_AMOUNT_BIOMES+1];
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
        numTiles[m_lvl[i].biome]++;
    }

    //TODO: place static objects
    //TODO: finish this
    int posX = 10;
    int posY = 10;
    for(uint32_t i = 0; i < (sizeX * sizeY); i++)
    {
        //todo: please rewrite this entire thing

        bool place = (rand() % 100) < MAPGEN_CHANCE_STATICOBJECT;
        if (!place) continue;
        //why is this r here and why does removing it crash program?
        StaticMapObject* r = getRandomObject(m_lvl[i].biome);
        if (r == nullptr) continue;

        StaticMapObject* obj = new StaticMapObject(*getRandomObject(m_lvl[i].biome));

        //TODO: base chance on numTiles['biome']
        //TODO 1)



        //TODO 2)



        //TODO 3)


        //TODO: old code below
        //TODO: how to get tile position? aka PosX and PosY
        ///>at((nPos.y * mapArea.x)+nPos.x)

        uint16_t vecX = m_tilemap.size() % sizeX;
        uint16_t vecY = 0;
        dbg_log("Placing object at array pos " << i << " ; " <<"Translated to vector position (" << vecX << ", " << vecY << ")")
        obj->setPosition(sf::Vector2f(posX, posY));
        posX += 100;
        posY += 100;
        m_staticObjects.push_back(obj);

    }


    //set up texture tilemap
    for (uint32_t i = 0; i < (sizeX * sizeY); i++)
    {
        assert(m_lvl[i].biome != LEVEL_BIOME_ID_NONE);
        m_tilemap.push_back(m_lvl[i].tilesetID);
    }


    return tilemap();
}

void MapGenerator::render(sf::RenderWindow *window)
{
    for(auto staticObject : m_staticObjects)
        staticObject->render(window);
}

