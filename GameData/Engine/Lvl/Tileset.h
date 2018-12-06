#ifndef ENFUSION_TILESET_H
#define ENFUSION_TILESET_H

#include "../Core/Engine.h"

template <>
struct std::less<sf::Vector2i>
{
inline bool operator()(const sf::Vector2i &vec1, const sf::Vector2i &vec2) const
{
    //TODO: Do some gross linear algebra here to compare magnitudes
    return true;
}
};

class Tileset {

public:
    Tileset(std::string setName, uint tileWidth = 32, uint tileHeight = 32);

    sf::Sprite& tileAt(uint row, uint column);

private:
    sf::Texture* tileSetTex;

    uint tileWidth;
    uint tileHeight;

    void fillTilesMap();

    std::map<sf::Vector2i, sf::Sprite> tiles;

};

#endif //ENFUSION_TILESET_H
