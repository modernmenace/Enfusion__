#ifndef ENFUSION_ANIMATEDSPRITE_H
#define ENFUSION_ANIMATEDSPRITE_H

#include "../Component.h"

#define PROTAGONIST_LAYERS 5

enum Layer_Type
{
    Layer_Type_BASE,
    Layer_Type_BOTTOM,
    Layer_Type_TOP,
    Layer_Type_HEAD,
    Layer_Type_WEAPON
};

class AnimatedSprite : public Component {

public:
    AnimatedSprite(string_t spriteSheet, int numberFrames, sf::IntRect characterSheetSize);
    ~AnimatedSprite();

    void initialize() override;
    void render(sf::RenderWindow* window) override;
    void switchState(uint8_t, uint8_t);
    void setPosition(sf::Vector2f);
    void addLayer(string_t, Layer_Type);
    void removeLayer(Layer_Type);

    inline void refreshState() { switchState(s_currentState_row, s_currentState_frame); }

    inline sf::IntRect bounds()             { return charRect; };
    inline sf::Sprite* getSprite()          { return s_layerMap[Layer_Type_BASE]; }

private:
    string_t     s_sheet;
    sf::IntRect  charRect;

    uint8_t directionalFrames;

    std::map<Layer_Type, sf::Sprite*> s_layerMap; //remember maps are ordered

    uint8_t s_currentState_row;
    uint8_t s_currentState_frame;
};


#endif //ENFUSION_ANIMATEDSPRITE_H
