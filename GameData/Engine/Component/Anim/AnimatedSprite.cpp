#include "AnimatedSprite.h"

AnimatedSprite::AnimatedSprite(std::string spriteSheet, int numberRows, int numberFrames, sf::IntRect characterSheetSize)
{
    this->spriteSheet = spriteSheet;
    this->charRect    = characterSheetSize;
    this->numRows     = numberRows;
    this->numFrames   = numberFrames;
}

void AnimatedSprite::initialize()
{
    assert(entity->hasComponent<Position>());
    this->sprite = sf::Sprite(AssetManager::Instance()->getTexture(spriteSheet), charRect);
    this->sprite.setPosition(entity->getComponent<Position>().getPosition());
    this->sprite.setScale(GLOBAL_SCALE_GAMEOBJECT);

    switchState(0, 0);
}

void AnimatedSprite::render(sf::RenderWindow *window)
{
    window->draw(sprite);
}

void AnimatedSprite::switchState(int row, int frame)
{
    auto sheetHeight = charRect.height;
    auto sheetWidth  = charRect.width;

    charRect.width  = sheetWidth  / numFrames;
    charRect.height = sheetHeight / numRows;

    if (row != 0)
        charRect.top  = (((row-1) * charRect.height) + (sheetHeight / numRows));
    else
        charRect.top = 0;

    if (frame != 0)
        charRect.left = (((frame-1) * charRect.width) + (sheetWidth / numFrames));
    else
        charRect.left = 0;


    sprite.setTextureRect(charRect);

    charRect.width = sheetWidth;
    charRect.height = sheetHeight;
}