#include "AnimatedSprite.h"
#include "../Base/Position.h"

//TODO: fix switchstate flickering
//TODO: find where this is updated
//TODO: idle frame when done moving

AnimatedSprite::AnimatedSprite(string_t spriteSheet, uint8_t sheetsPerRow, int numberFrames, sf::IntRect characterSheetSize, sf::Vector2i sheet)
{
    this->s_sheet           = spriteSheet;
    this->charRect          = characterSheetSize;
    this->sheetsPerRow      = sheetsPerRow;
    this->directionalFrames = numberFrames;
    this->sprite_sheetMap   = sheet;
}

void AnimatedSprite::initialize()
{
    assert(entity->hasComponent<Position>());

    charRect.left += (sprite_sheetMap.x * (charRect.width));
    charRect.top  += (sprite_sheetMap.y * (charRect.height));

    this->sprite = sf::Sprite(AssetManager::Instance()->getTexture(s_sheet), charRect);
    this->sprite.setPosition(entity->getComponent<Position>().getPosition());
    this->sprite.setScale(3,3);

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

    charRect.width  = sheetWidth  / directionalFrames;
    charRect.height = sheetHeight / sheetsPerRow;

    if (row != 0)
        charRect.top  = (((row-1) * charRect.height) + (sheetHeight / sheetsPerRow));
    else
        charRect.top = 0;

    if (frame != 0)
        charRect.left = (((frame-1) * charRect.width * sprite_sheetMap.x) + (sheetWidth / directionalFrames));
    else
        charRect.left = 0;

    //TODO: flickering between characters?
    charRect.left += (sprite_sheetMap.x * (charRect.width));
    charRect.top  += (sprite_sheetMap.y * (charRect.height));

    sprite.setTextureRect(charRect);

    charRect.width = sheetWidth;
    charRect.height = sheetHeight;
}