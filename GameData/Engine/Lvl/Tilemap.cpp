#include "Tilemap.h"

Tilemap::Tilemap(std::string tileSetName)
{
    t = new Tileset(tileSetName);
    initialize();
}

void Tilemap::initialize()
{

}