#ifndef ENFUSION___BIOMEMANAGER_H
#define ENFUSION___BIOMEMANAGER_H

#include "Biome.h"

#define LEVEL_AMOUNT_BIOMES     2

#define LEVEL_BIOME_ID_NONE     0
#define LEVEL_BIOME_ID_WOODLAND 1
#define LEVEL_BIOME_ID_DESERT   2


class BiomeManager
{

public:
    BiomeManager();
    ~BiomeManager();
    static BiomeManager* Instance();
    inline Biome* biome(uint16_t id) { return biomes[id]; }

private:
    static BiomeManager* m_Instance;
    Biome* biomes[LEVEL_AMOUNT_BIOMES];

};

#endif //ENFUSION___BIOMEMANAGER_H
