#ifndef ENFUSION_TILEMAP_H
#define ENFUSION_TILEMAP_H

#include "Tileset.h"

class Tilemap {

public:
    Tilemap(std::string tileSetName);

    void initialize();
    void render(sf::RenderWindow* window);

private:
    Tileset* t = nullptr;
    std::string tileSetName;

};


#endif //ENFUSION_TILEMAP_H
