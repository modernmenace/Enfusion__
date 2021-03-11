#include "AnimatedSprite.h"
#include "../Base/Position.h"

//TODO: documentation
//TODO: generalize this as a animated character, maybe move some shared movement here

AnimatedSprite::AnimatedSprite(string_t spriteSheet, int numberFrames, sf::IntRect characterSheetSize)
{
    this->s_sheet           = spriteSheet;
    this->charRect          = characterSheetSize;
    this->directionalFrames = numberFrames;
    this->s_layers          = 1;
}

void AnimatedSprite::initialize()
{
    assert(entity->hasComponent<Position>());

    s_layerSprites.push_back(sf::Sprite(AssetManager::Instance()->getTexture(s_sheet), charRect));
    s_layerSprites[0].setPosition(entity->getComponent<Position>().getPosition());
    s_layerSprites[0].setScale(3,3);

    switchState(0, 0);
}

void AnimatedSprite::addLayer(string_t spriteSheet)
{
    s_layers++;
    s_layerSprites.push_back(sf::Sprite(AssetManager::Instance()->getTexture(spriteSheet), charRect));
    //TODO: s_layers is re-editing first layer
    s_layerSprites[s_layers-1].setPosition(entity->getComponent<Position>().getPosition());
    s_layerSprites[s_layers-1].setScale(3,3);
}

void AnimatedSprite::setPosition(sf::Vector2f pos)
{
    for(int i = 0; i < s_layers; i++)
    {
        s_layerSprites[i].setPosition(pos);
    }
}

void AnimatedSprite::render(sf::RenderWindow *window)
{
    for(int i = 0; i < s_layers; i++)
    {
        window->draw(s_layerSprites[i]);
    }
}

void AnimatedSprite::switchState(uint8_t row, uint8_t frame)
{
    if (row > 4)                   row = 4;
    if (frame > directionalFrames) frame = directionalFrames;

    sf::IntRect texRect;
    texRect.height = charRect.height / 4;
    texRect.width  = charRect.width / directionalFrames;

    texRect.top  = (texRect.height * row);
    texRect.left = (texRect.width * frame);

    for(int i = 0; i < s_layers; i++)
    {
        s_layerSprites[i].setTextureRect(texRect);
    }
}