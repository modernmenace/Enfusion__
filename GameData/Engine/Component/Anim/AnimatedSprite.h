#ifndef ENFUSION_ANIMATEDSPRITE_H
#define ENFUSION_ANIMATEDSPRITE_H

#include "../Component.h"

class AnimatedSprite : public Component {

public:
    AnimatedSprite(string_t spriteSheet, int numberFrames, sf::IntRect characterSheetSize);

    void initialize() override;
    void render(sf::RenderWindow* window) override;
    void switchState(uint8_t, uint8_t);
    void setPosition(sf::Vector2f);
    void addLayer(string_t);

    inline sf::IntRect bounds()             { return charRect; };
    inline sf::Sprite& getSprite()          { return s_layerSprites[0]; }

private:
    string_t     s_sheet;
    sf::IntRect  charRect;

    uint8_t directionalFrames;

    int s_layers;
    std::vector<sf::Sprite> s_layerSprites;
};


#endif //ENFUSION_ANIMATEDSPRITE_H
