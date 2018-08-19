#include "Sprite.h"
#include "../../Entity/Entity.h"

/*
 *  Sprite Component
 *
 *  DESC: Draws a sprite at the entity's position
 *
 */

Sprite::Sprite(std::string spriteName)
{
    dbg_log("Component Regsistered: " << registered)
    REGISTER_COMPONENT
    this->spriteName = spriteName;
}

void Sprite::initialize()
{
    this->sprite = sf::Sprite(AssetManager::getTexture(spriteName));
    this->sprite.setPosition(entity->position);
    this->sprite.setScale(GLOBAL_SCALE_GAMEOBJECT);
}

void Sprite::render(sf::RenderWindow *window)
{
    window->draw(sprite);
}