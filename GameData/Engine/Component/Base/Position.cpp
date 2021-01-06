#include "Position.h"
#include "Sprite.h"
#include "../Anim/AnimatedSprite.h"
#include "../../../Lvl/MapGenerator.h"


//todo: fundamental changes here - need more info
//todo: need: tile if on map
//todo: absolute for UI position ( no rect)

Position::Position(sf::Vector2f position)
{
    p_pos = position;
}

void Position::setPosition(sf::Vector2f pos)
{
    //check if tile needs updated
    if (p_tile)
    {
        auto* newTile = &MapGenerator::Instance()->map()->m_tiles[resolvePositionToTile(pos.x, pos.y)];
        if (newTile != p_tile)
            p_tile = newTile;
    }

    p_pos = pos;
    if (entity->hasComponent<Sprite>())
        entity->getComponent<Sprite>().updatePosition(p_pos);
    if (entity->hasComponent<AnimatedSprite>())
        entity->getComponent<AnimatedSprite>().setPosition(p_pos);
}

void Position::setPosition(Tile* tile)
{
    p_pos  = tile->position;
    p_tile = tile;

    setPosition(p_pos);
}