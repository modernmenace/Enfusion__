#include "Tileset.h"

// TODO: Switch to sprite

Tileset::Tileset(std::string setName, uint tileWidth, uint tileHeight)
{
    tileSetTex = &AssetManager::getTexture(setName);
    this->tileWidth  = tileWidth;
    this->tileHeight = tileHeight;

    fillTilesMap();
}

void Tileset::fillTilesMap()
{
    //TODO: Finish filling tileset

    // get set width and height
    auto setWidth  = tileSetTex->getSize().x;
    auto setHeight = tileSetTex->getSize().y;

    // use tile width and height for some math cancer
    // go row by row?
    uint row = 0;
    uint col = 0;
    forever
    {
        sf::Vector2i vec(row, col);
        sf::IntRect spriteRect(0, 0, tileWidth, tileHeight);
        sf::Sprite* sprite = new sf::Sprite(*tileSetTex, spriteRect);
        sprite->setScale(GLOBAL_SCALE_TILE);
        auto pair = std::make_pair(vec, *sprite);
        tiles.insert(pair);
        dbg_log("Tileset Map Size: " << tiles.size())
        //TODO: first increase col, then row
        col++;
        break;
    }
}

sf::Sprite& Tileset::tileAt(uint row, uint column)
{
    return tiles.at(sf::Vector2i(row, column));
}