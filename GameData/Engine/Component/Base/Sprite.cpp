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

Sprite::Sprite(sf::Texture& texture)
{
    s_tex = &texture;
}

void Sprite::initialize()
{
    assert(entity->hasComponent<Position>());
    if (s_name.empty())
    {
        this->sprite = sf::Sprite(*s_tex);
        this->sprite.setPosition(entity->getComponent<Position>().getPosition());
        this->sprite.setScale(GLOBAL_SCALE_GAMEOBJECT);
        return;
    }
    this->sprite = sf::Sprite(AssetManager::Instance()->getTexture(s_name));
    this->sprite.setPosition(entity->getComponent<Position>().getPosition());
    this->sprite.setScale(GLOBAL_SCALE_GAMEOBJECT);
}

void Sprite::render(sf::RenderWindow *window, uint8_t z)
{
    if (s_visible)
        window->draw(sprite);
}

sf::Vector2u Sprite::center()
{
    sf::Vector2u center;

    sf::FloatRect gBounds = sprite.getGlobalBounds();

    center.x = gBounds.left + (gBounds.width / 2);
    center.y = gBounds.top  - (gBounds.height / 2);

    return center;
}