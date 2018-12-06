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
    // fill std::map

    // get set width and height
    auto setWidth  = tileSetTex->getSize().x;
    auto setHeight = tileSetTex->getSize().y;

    // use tile width and height for some math cancer
    // go row by row?
    for(;;)
    {
        // first row?
        int row = 0;
        for(;;)
        {
            int index = 0;
            uint pos  = 0;
            sf::Vector2i vec(row, index);
            sf::IntRect spriteRect(0, 0, 100, 100);
            //TODO: error is here
            sf::Sprite* sprite = new sf::Sprite(*tileSetTex, spriteRect);
            auto pair = std::make_pair(vec, *sprite);
            tiles.insert(pair);
            //TODO: this compiles now, test??
            dbg_log("Tileset Map Size: " << tiles.size())
            break;
        }


        break;
    }
}

sf::Sprite& Tileset::tileAt(uint row, uint column)
{
    //return pointer to sprite contained in std::map
}