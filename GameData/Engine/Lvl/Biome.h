#ifndef ENFUSION___BIOME_H
#define ENFUSION___BIOME_H

#include "../Core/Engine.h"
#include <SFML/Graphics/RectangleShape.hpp>

struct Tile
{
    uint16_t biome;
    uint16_t tilesetID;
};

class Biome
{

public:
    virtual void generate(sf::RectangleShape area) {};

};


#endif //ENFUSION___BIOME_H
