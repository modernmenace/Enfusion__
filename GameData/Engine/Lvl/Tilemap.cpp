#include "Tilemap.h"

// USING SFML TUTORIAL
// https://www.sfml-dev.org/tutorials/2.1/graphics-vertex-array.php

Tilemap::Tilemap(std::string tileSetName, const int* tiles, uint width, uint height) :
    tileSize(TILESHEET_TILE_WIDTH, TILESHEET_TILE_HEIGHT)
{
    this->tileset  = AssetManager::getTexture(tileSetName);
    this->width    = width;
    this->height   = height;

    //setup tiles, doing this awful way due to

    for(int i = 0; i < width * height; i++)
        this->tiles.push_back(tiles[i]);
}

void Tilemap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
// apply the transform
    states.transform *= getTransform();

    // apply the tileset texture
    states.texture = &tileset;

    // draw the vertex array
    target.draw(vertices, states);
}

void Tilemap::initialize()
{;
    vertices.setPrimitiveType(sf::Quads);
    vertices.resize(width * height * 4);

    // populate the vertex array, with one quad per tile
    for (unsigned int i = 0; i < width; ++i)
        for (unsigned int j = 0; j < height; ++j)
        {
            // get the current tile number
            int tileNumber = tiles[i + j * width];

            // find its position in the tileset texture
            int tu = tileNumber % (tileset.getSize().x / tileSize.x);
            int tv = tileNumber / (tileset.getSize().y / tileSize.y);

            // get a pointer to the current tile's quad
            sf::Vertex* quad = &vertices[(i + j * width) * 4];

            // define its 4 corners
            quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
            quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
            quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
            quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

            // define its 4 texture coordinates
            quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
            quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
            quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
            quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
        }
}

void Tilemap::render(sf::RenderWindow *window)
{
    window->draw(*this);
}