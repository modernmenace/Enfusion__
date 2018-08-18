#include "Sprite.h"
#include "../../Entity/Entity.h"

/*
 *  TODO: THIS IS WORKING!!!!!!! Now need to fix the player class
 *
 *
 */

Sprite::Sprite(std::string spriteName)
{
    dbg_log("Sprite: We have a sprite name of '" << spriteName << "'")
    this->spriteName = spriteName;
}

void Sprite::initialize()
{
    dbg_log("Entity has a sprite!")

    this->sprite = sf::Sprite(AssetManager::getTexture(spriteName));
    this->sprite.setPosition(entity->position);
    this->sprite.setScale(GLOBAL_SCALE_GAMEOBJECT);
}

void Sprite::update()
{

}

void Sprite::render(sf::RenderWindow *window)
{
    window->draw(sprite);
}