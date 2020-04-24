#ifndef ENFUSION___BIOMEMANAGER_H
#define ENFUSION___BIOMEMANAGER_H

#include "Biome.h"

#define LEVEL_AMOUNT_BIOMES     2

#define LEVEL_BIOME_ID_WOODLAND 0
#define LEVEL_BIOME_ID_DESERT   1


class BiomeManager
{

public:
    BiomeManager();
    ~BiomeManager();
    static BiomeManager* Instance();


private:
    static BiomeManager* m_Instance;
    Biome* biomes[LEVEL_AMOUNT_BIOMES];

};

#endif //ENFUSION___BIOMEMANAGER_H
