#include "Sprite.h"
#include "../../Entity/Entity.h"
#include "../Base/Position.h"

/*
 *  Sprite Component
 *
 *  DESC: Draws a sprite at the entity's position
 *
 */

Sprite::Sprite(std::string spriteName)
{
    this->spriteName = spriteName;
}

void Sprite::initialize()
{
    assert(entity->hasComponent<Position>());
    this->sprite = sf::Sprite(AssetManager::Instance()->getTexture(spriteName));
    this->sprite.setPosition(entity->getComponent<Position>().getPosition());
    this->sprite.setScale(GLOBAL_SCALE_GAMEOBJECT);
}

void Sprite::render(sf::RenderWindow *window)
{
    if (visible)
        window->draw(sprite);
}
