#ifndef ENFUSION_TILEMAP_H
#define ENFUSION_TILEMAP_H

#include "../Core/Engine.h"
#include "../../Lvl/LvlStructs.h"
#include <vector>

#define CULLING_TILE_DISTANCE_X 32
#define CULLING_TILE_DISTANCE_Y 20

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

    #if DEBUG_ENABLE_TILE_OUTLINES == 1
    struct t_outline
    {
        Tile*              tile;
        sf::RectangleShape rect;
    };
    bool t_drawOutlines = false;
    #endif

    std::vector<t_outline> t_outlines;


    Map* t_map = nullptr;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};


#endif //ENFUSION_TILEMAP_H
