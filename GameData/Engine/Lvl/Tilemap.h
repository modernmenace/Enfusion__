#ifndef ENFUSION_TILEMAP_H
#define ENFUSION_TILEMAP_H

#include "Tileset.h"

class Tilemap {

public:
    Tilemap(std::string tileSetName);

    void initialize();

private:
    Tileset* t = nullptr;

};


#endif //ENFUSION_TILEMAP_H
