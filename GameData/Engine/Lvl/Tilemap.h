#ifndef ENFUSION_TILEMAP_H
#define ENFUSION_TILEMAP_H

#include "../Core/Engine.h"
#include <vector>

#define TILESHEET_TILE_WIDTH  128
#define TILESHEET_TILE_HEIGHT 128

class Tilemap : public sf::Drawable, public sf::Transformable {

public:
    Tilemap(std::string tileSetName, std::vector<int> tiles, uint16_t width, uint16_t height);

    Tilemap(const sf::VertexArray &tiles);

    void initialize();
    void render(sf::RenderWindow* window);

private:
    sf::Texture     tileset;
    sf::VertexArray vertices;
    sf::Vector2u    tileSize;

    uint16_t width;
    uint16_t height;

    std::vector<int> tiles;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};


#endif //ENFUSION_TILEMAP_H
