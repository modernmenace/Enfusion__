#ifndef ENFUSION___MAPGENERATOR_H
#define ENFUSION___MAPGENERATOR_H

#include "../Engine/Core/Engine.h"
#include "BiomeManager.h"
#include "Biomes/Objects/StaticMapObject.h"
#include "../Engine/Lvl/Tilemap.h"

#define LEVEL_BIOME_SIZE_MIN 60
#define LEVEL_BIOME_SIZE_MAX 200

#define MAPGEN_CHANCE_STATICOBJECT 1

class MapGenerator {

public:
    MapGenerator();
    ~MapGenerator();
    static MapGenerator* Instance();
    std::vector<int> generateMap(uint16_t sizeX, uint16_t sizeY, uint16_t tileSize);

    void render(sf::RenderWindow* window);

    inline sf::Vector2i size()        { return m_size; }
    inline sf::Vector2i boundaries()  { return m_boundaries; }
    inline std::vector<Tile>* map()   { return &m_lvl; }

    std::vector<StaticMapObject*>* staticMapObjects() { return &m_staticObjects; }

private:
    static MapGenerator*          m_Instance;
    std::vector<Tile>             m_lvl;
    std::vector<StaticMapObject*> m_staticObjects;
    std::vector<int>              m_tileVec;
    sf::Vector2i                  m_size;
    sf::Vector2i                  m_boundaries;
    uint16_t                      m_tileSize;

    std::vector<WeightedMapObject> m_biomeObjects[LEVEL_AMOUNT_BIOMES+1];

    void populateBiomeObjects();

    StaticMapObject* getRandomObject(uint16_t biomeID)
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
};


#endif //ENFUSION___MAPGENERATOR_H
