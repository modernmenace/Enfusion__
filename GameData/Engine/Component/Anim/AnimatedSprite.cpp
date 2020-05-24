#include "AnimatedSprite.h"
#include "../Base/Position.h"

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

void AnimatedSprite::switchState(uint8_t row, uint8_t frame)
{
    if (row > 4)                   row = 4;
    if (frame > directionalFrames) frame = directionalFrames;

    sf::IntRect texRect;
    texRect.height = charRect.height / 4;
    texRect.width  = charRect.width / directionalFrames;

    texRect.top  = (texRect.height * row)  + (sprite_sheetMap.y * (charRect.height));
    texRect.left = (texRect.width * frame) + (sprite_sheetMap.x * (charRect.width));

    sprite.setTextureRect(texRect);
}