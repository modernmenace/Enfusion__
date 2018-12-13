#ifndef ENFUSION_TILEMAP_H
#define ENFUSION_TILEMAP_H

#include "../Core/Engine.h"

class Tilemap : public sf::Drawable, public sf::Transformable {

public:
    Tilemap(std::string tileSetName, const int* tiles, sf::Vector2u tileSize = sf::Vector2u(32, 32));

    void initialize();
    void render(sf::RenderWindow* window);

private:
    sf::Texture     tileset;
    sf::VertexArray vertices;
    sf::Vector2u    tileSize;

    uint width  = 16;
    uint height = 8;

    const int* tiles;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};


#endif //ENFUSION_TILEMAP_H
