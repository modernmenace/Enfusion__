#include "Sprite.h"
#include "../../Entity/Entity.h"

/*
 *  Sprite Component
 *
 *  DESC: Draws a sprite at the entity's position
 *
 */

Sprite::Sprite(std::string spriteName) : Component("Sprite")
{
    REGISTER_COMPONENT
    this->spriteName = spriteName;
    for(const auto &i : ComponentMap)
        dbg_log("Component Map: " << i.first << ", " << i.second)
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