#ifndef ENFUSION___BIOME_H
#define ENFUSION___BIOME_H

#include "../Core/Engine.h"
#include <SFML/Graphics/RectangleShape.hpp>

//TODO: Play with these values
#define LEVEL_BIOME_SIZE_MIN 100
#define LEVEL_BIOME_SIZE_MAX 200

struct Tile
{
    uint16_t biome;
    uint16_t tilesetID;
};

class Biome
{

public:
    virtual void generate(sf::RectangleShape area, std::vector<Tile>* map) {};

};


#endif //ENFUSION___BIOME_H
