#ifndef ENFUSION_SPRITE_H
#define ENFUSION_SPRITE_H

#include "../Component.h"

class Sprite : public Component {

public:
    Sprite(std::string spriteName = MISSING_TEXTURE);

    void initialize()                     override;
    void render(sf::RenderWindow* window) override;
    std::string spriteName;
    bool visible = true;

    inline sf::Sprite& getSprite()
    {
        return sprite;
    }

private:
    sf::Sprite sprite;


};


#endif //ENFUSION_SPRITE_H
