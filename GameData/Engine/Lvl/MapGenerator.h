#ifndef ENFUSION___MAPGENERATOR_H
#define ENFUSION___MAPGENERATOR_H

#include "../Core/Engine.h"

class MapGenerator {

public:
    MapGenerator();
    static MapGenerator* Instance();
    std::vector<int> generateMap(uint16_t sizeX, uint16_t sizeY);



private:
    static MapGenerator* m_Instance;
    std::vector<int> lvl;


};


#endif //ENFUSION___MAPGENERATOR_H
