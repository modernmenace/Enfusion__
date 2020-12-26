#ifndef ENFUSION_TILEMAP_H
#define ENFUSION_TILEMAP_H

#include "../Core/Engine.h"
#include "../../Lvl/LvlStructs.h"
#include <vector>

#define CULLING_TILE_DISTANCE_X 20
#define CULLING_TILE_DISTANCE_Y 15

class Tilemap : public sf::Drawable, public sf::Transformable {

public:
    Tilemap(std::string tileSetName, Map* tiles, sf::Vector2i size, uint16_t tileSize);
    ~Tilemap();

    void initialize();
    void render(sf::RenderWindow* window);
    void showOutlines(bool);

    inline uint16_t getTileSize()     { return tileSize; };
    inline bool     outlinesShowing() { return t_drawOutlines; }
private:
    sf::Texture     tileset;
    sf::VertexArray vertices;

    uint16_t width;
    uint16_t height;
    uint16_t tileSize;

    Map* t_map = nullptr;

    struct t_outline
    {
        Tile*              tile;
        sf::RectangleShape rect;
    };
    bool t_drawOutlines = false;
    std::vector<t_outline> t_outlines;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};


#endif //ENFUSION_TILEMAP_H
