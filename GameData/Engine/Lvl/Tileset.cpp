#include "Tileset.h"

Tileset::Tileset(std::string setName, uint tileWidth, uint tileHeight)
{
    tiles = &AssetManager::getTexture(setName);
    this->tileWidth  = tileWidth;
    this->tileHeight = tileHeight;
}

sf::Texture& Tileset::tileAt(uint row, uint column)
{
    
}