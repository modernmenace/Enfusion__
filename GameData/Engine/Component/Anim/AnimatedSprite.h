#ifndef ENFUSION_ANIMATEDSPRITE_H
#define ENFUSION_ANIMATEDSPRITE_H

#include "../Component.h"

class AnimatedSprite : public Component {

public:
    AnimatedSprite(string_t spriteSheet, uint8_t sheetsPerRow, int numberFrames, sf::IntRect characterSheetSize, sf::Vector2i sheet);

    void initialize() override;
    void render(sf::RenderWindow* window) override;
    void switchState(int row, int frame);

    inline sf::IntRect bounds()             { return charRect; };
    inline void setPosition(sf::Vector2f p) { sprite.setPosition(p); }
    inline sf::Sprite& getSprite()          { return sprite; }

private:
    string_t     s_sheet;
    sf::IntRect  charRect;

    uint8_t sheetsPerRow;
    uint8_t directionalFrames;

    sf::Sprite   sprite;
    sf::Vector2i sprite_sheetMap;
};


#endif //ENFUSION_ANIMATEDSPRITE_H
