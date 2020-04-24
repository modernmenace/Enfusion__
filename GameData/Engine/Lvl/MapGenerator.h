#ifndef ENFUSION___MAPGENERATOR_H
#define ENFUSION___MAPGENERATOR_H

#include "../Core/Engine.h"
#include "BiomeManager.h"

//TODO: tilemap to array so that other functions can access it?

class MapGenerator {

public:
    static MapGenerator* Instance();
    std::vector<int> generateMap(uint16_t sizeX, uint16_t sizeY);

    inline sf::Vector2i size()        { return m_size; }
    inline std::vector<int> tilemap() { return m_tilemap; }
    inline std::vector<Tile>* map()   { return &m_lvl; }

private:
    static MapGenerator* m_Instance;
    std::vector<Tile>    m_lvl;
    std::vector<int>     m_tilemap;
    sf::Vector2i         m_size;

};


#endif //ENFUSION___MAPGENERATOR_H
