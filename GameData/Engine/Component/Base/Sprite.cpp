#include "Sprite.h"
#include "../../Entity/Entity.h"
#include "../Base/Position.h"

/*
 *  Sprite Component
 *
 *  DESC: Draws a sprite at the entity's position
 *
 */

Sprite::Sprite(string_t spriteName)
{
    s_name = spriteName;
}

void Sprite::initialize()
{
    assert(entity->hasComponent<Position>());
    this->sprite = sf::Sprite(AssetManager::Instance()->getTexture(s_name));
    this->sprite.setPosition(entity->getComponent<Position>().getPosition());
    this->sprite.setScale(GLOBAL_SCALE_GAMEOBJECT);
}

void Sprite::render(sf::RenderWindow *window)
{
    if (visible)
        window->draw(sprite);
}
