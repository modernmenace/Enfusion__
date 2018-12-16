#ifndef ENFUSION_TILEMAP_H
#define ENFUSION_TILEMAP_H

#include "../Core/Engine.h"

#define TILESHEET_TILE_WIDTH  128
#define TILESHEET_TILE_HEIGHT 128

class Tilemap : public sf::Drawable, public sf::Transformable {

public:
    Tilemap(std::string tileSetName, const int* tiles, uint width, uint height);

    void initialize();
    void render(sf::RenderWindow* window);

private:
    sf::Texture     tileset;
    sf::VertexArray vertices;
    sf::Vector2u    tileSize;

    uint width;
    uint height;

    const int* tiles;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};


#endif //ENFUSION_TILEMAP_H
