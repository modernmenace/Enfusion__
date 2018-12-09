#include "Tilemap.h"

Tilemap::Tilemap(std::string tileSetName)
{
    this->tileSetName = tileSetName;
}

void Tilemap::initialize()
{
    t = new Tileset(tileSetName);
}

void Tilemap::render(sf::RenderWindow *window)
{
    window->draw(t->tileAt(0, 0));
}