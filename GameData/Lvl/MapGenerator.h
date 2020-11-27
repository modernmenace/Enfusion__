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
    ~MapGenerator() { if (m_Instance) delete m_Instance; }
    static MapGenerator* Instance();
    Map generateMap(uint16_t sizeX, uint16_t sizeY, uint16_t tileSize);

    inline sf::Vector2i size()        { return m_size; }
    inline sf::Vector2i boundaries()  { return m_boundaries; }
    inline std::vector<Tile>* map()   { return &m_lvl; }

private:
    static MapGenerator*          m_Instance;
    std::vector<Tile>             m_lvl;
    sf::Vector2i                  m_size;
    sf::Vector2i                  m_boundaries;
    uint16_t                      m_tileSize;

    std::vector<WeightedMapObject> m_biomeObjects[LEVEL_AMOUNT_BIOMES+1];

    void populateBiomeObjects();

    StaticMapObject* getRandomObject(uint16_t biomeID);
};


#endif //ENFUSION___MAPGENERATOR_H
