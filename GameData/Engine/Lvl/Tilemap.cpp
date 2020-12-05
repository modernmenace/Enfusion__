#include "Tilemap.h"
#include <utility>
#include "../../Lvl/MapGenerator.h"

//todo: Overhaul
//todo:  2 - Blocked tiles (redo collision)
//todo:  3 - Rethink how static objects are handled
//todo:  4 - store player tile andswa show on debug menu

/************************************************************************
 * FUNCTION :       Tilemap::Tilemap
 *
 * DESCRIPTION :
 *       Constructor, set up parameters
 *
 *  INPUTS:  string tileSetName :
 *           vector<Tile> tiles : vector containing
 *           Vector2i    size   : size of the tile map (width and height)
 *           uint16_t  tileSize : size of individual tiles
 *
 *  OUTPUTS: NONE
 *
 *  VERSION   	DATE    		WHO     DETAIL
 *  V1.00.00   	2020.11.25 	    JCB     Documentation Start
 *
 ************************************************************************/

Tilemap::Tilemap(std::string tileSetName, Map* tiles, sf::Vector2i size, uint16_t tileSize)
{
    this->tileset  = AssetManager::Instance()->getTexture(tileSetName);
    this->width    = size.x;
    this->height   = size.y;

    this->t_map      = tiles;
    this->tileSize = tileSize;
}

/************************************************************************
 * FUNCTION :       Tilemap::~Tilemap
 *
 * DESCRIPTION :
 *       Destructor, delete static map objects
 *
 *  INPUTS:  string tileSetName :
 *           vector<Tile> tiles : vector containing
 *           Vector2i    size   : size of the tile map (width and height)
 *           uint16_t  tileSize : size of individual tiles
 *
 *  OUTPUTS: NONE
 *
 *  VERSION   	DATE    		WHO     DETAIL
 *  V1.00.00   	2020.11.25 	    JCB     Documentation Start
 *
 ************************************************************************/

Tilemap::~Tilemap()
{
    for(uint32_t i = 0; i < t_map->m_mapObjects.size(); i++)
        delete t_map->m_mapObjects[i];
}

/************************************************************************
 * FUNCTION :       Tilemap::draw
 *
 * DESCRIPTION :
 *       Draw the tilemap to the specified target
 *
 *  INPUTS:  RenderTarget& target : target to draw to
 *           RenderStates states  : render states to be used
 *
 *  OUTPUTS: NONE
 *
 *  VERSION   	DATE    		WHO     DETAIL
 *  V1.00.00   	2020.11.25 	    JCB     Documentation Start
 *
 ************************************************************************/

void Tilemap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // apply the transform
    auto transform = getTransform();
    transform.scale(GLOBAL_SCALE_TILE);
    states.transform *= transform;

    // apply the tileset texture
    states.texture = &tileset;
    // draw the vertex array
    target.draw(vertices, states);
}

/************************************************************************
 * FUNCTION :       Tilemap::initialize
 *
 * DESCRIPTION :
 *       Initialize the tile map
 *
 *  INPUTS:  NONE
 *
 *  OUTPUTS: NONE
 *
 *  VERSION   	DATE    		WHO     DETAIL
 *  V1.00.00   	2020.11.25 	    JCB     Documentation Start
 *
 ************************************************************************/

void Tilemap::initialize()
{;
    vertices.setPrimitiveType(sf::Quads);
    vertices.resize(width * height * 4);

    // populate the vertex array, with one quad per tile
    for (unsigned int i = 0; i < width; ++i)
        for (unsigned int j = 0; j < height; ++j)
        {
            // get the current tile number
            int tileNumber = t_map->m_tiles[i + j * width].tilesetID;

            // find its position in the tileset texture
            int tu = tileNumber % (tileset.getSize().x / tileSize);
            int tv = tileNumber / (tileset.getSize().y / tileSize);

            // get a pointer to the current tile's quad
            sf::Vertex* quad = &vertices[(i + j * width) * 4];

            // define its 4 corners
            quad[0].position = sf::Vector2f(i * tileSize, j * tileSize);
            quad[1].position = sf::Vector2f((i + 1) * tileSize, j * tileSize);
            quad[2].position = sf::Vector2f((i + 1) * tileSize, (j + 1) * tileSize);
            quad[3].position = sf::Vector2f(i * tileSize, (j + 1) * tileSize);

            // define its 4 texture coordinates
            quad[0].texCoords = sf::Vector2f(tu * tileSize, tv * tileSize);
            quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize, tv * tileSize);
            quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize, (tv + 1) * tileSize);
            quad[3].texCoords = sf::Vector2f(tu * tileSize, (tv + 1) * tileSize);
        }
}

/************************************************************************
 * FUNCTION :       Tilemap::render
 *
 * DESCRIPTION :
 *       Render the tilemap
 *
 *  INPUTS:  RenderWindow* window : Window to render to
 *
 *  OUTPUTS: NONE
 *
 *  VERSION   	DATE    		WHO     DETAIL
 *  V1.00.00   	2020.11.25 	    JCB     Documentation Start
 *
 ************************************************************************/

void Tilemap::render(sf::RenderWindow *window)
{
    window->draw(*this);

    for(auto staticObject : t_map->m_mapObjects)
        staticObject->render(window);

    for(auto& outline : t_outlines)
        window->draw(outline);

}

void Tilemap::showOutlines(bool show)
{
    if (!show)
    {
        t_drawOutlines = false;
        t_outlines.clear();
        return;
    }

    //todo: push outlines to array
    auto mSize = MapGenerator::Instance()->size();
    sf::Vector2f tSize;
    tSize.x = (MapGenerator::Instance()->tileSize() * GLOBAL_SCALE_TILE.x);
    tSize.y = (MapGenerator::Instance()->tileSize() * GLOBAL_SCALE_TILE.y);

    uint16_t posX = 0;
    uint16_t posY = 0;
    for(uint32_t i = 0; i < (mSize.x * mSize.y); i++)
    {
        if (posX++ == mSize.x)
        {
            posY++;
            posX = 0;
        }

        sf::Vector2f tempPos;
        tempPos.x = posX * 32;
        tempPos.y = posY * 32;

        sf::RectangleShape sh;
        sh.setSize(tSize);
        sh.setOutlineColor(sf::Color::Black);
        sh.setOutlineThickness(1);
        sh.setFillColor(sf::Color::Transparent);
        sh.setPosition(tempPos);
        t_outlines.push_back(sh);
    }

    t_drawOutlines = true;
}