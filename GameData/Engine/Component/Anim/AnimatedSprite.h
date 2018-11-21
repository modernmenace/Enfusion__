#ifndef ENFUSION_ANIMATEDSPRITE_H
#define ENFUSION_ANIMATEDSPRITE_H

#include "../../Core/Engine.h"
#include "../Component.h"
#include "../Base/Position.h"

class AnimatedSprite : public Component {

public:
    AnimatedSprite(std::string spriteSheet, int numberRows, int numberFrames, sf::IntRect characterSheetSize);

    void initialize() override;
    void render(sf::RenderWindow* window) override;
    void switchState(int row, int frame);

    inline sf::Sprite& getSprite()
    {
        return sprite;
    }

private:
    std::string  spriteSheet;
    sf::IntRect  charRect;

    int numRows;
    int numFrames;

    sf::Sprite sprite;

};


#endif //ENFUSION_ANIMATEDSPRITE_H
