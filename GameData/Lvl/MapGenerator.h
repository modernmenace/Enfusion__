#ifndef ENFUSION___MAPGENERATOR_H
#define ENFUSION___MAPGENERATOR_H

#include "../Engine/Core/Engine.h"
#include "BiomeManager.h"
#include "Biomes/Objects/StaticMapObject.h"

#define LEVEL_BIOME_SIZE_MIN 60
#define LEVEL_BIOME_SIZE_MAX 200

class MapGenerator {

public:
    MapGenerator();
    static MapGenerator* Instance();
    std::vector<int> generateMap(uint16_t sizeX, uint16_t sizeY);

    void render(sf::RenderWindow* window);

    inline sf::Vector2i size()        { return m_size; }
    inline std::vector<int> tilemap() { return m_tilemap; }
    inline std::vector<Tile>* map()   { return &m_lvl; }

private:
    static MapGenerator*          m_Instance;
    std::vector<Tile>             m_lvl;
    std::vector<StaticMapObject*> m_staticObjects; // TODO: *this is not unallocated
    std::vector<int>              m_tilemap;
    sf::Vector2i                  m_size;

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
