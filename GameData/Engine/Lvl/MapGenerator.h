#ifndef ENFUSION___MAPGENERATOR_H
#define ENFUSION___MAPGENERATOR_H

#include "../Core/Engine.h"

class MapGenerator {

public:
    static MapGenerator* Instance();
    std::vector<int> generateMap(uint16_t sizeX, uint16_t sizeY);
    inline sf::Vector2i size() { return m_size; }


private:
    static MapGenerator* m_Instance;
    std::vector<int> lvl;

    sf::Vector2i m_size;


};


#endif //ENFUSION___MAPGENERATOR_H
