#ifndef ENFUSION_SPRITE_H
#define ENFUSION_SPRITE_H

#include "../Component.h"

class Sprite : public Component {

public:
    Sprite(string_t spriteName = MISSING_TEXTURE);

    void initialize()                     override;
    void render(sf::RenderWindow* window) override;
    bool visible = true;

    inline void updatePosition(sf::Vector2f p)  { sprite.setPosition(p); }
    inline sf::Sprite& getSprite(){ return sprite; }

private:
    sf::Sprite sprite;
    string_t   s_name;


};


#endif //ENFUSION_SPRITE_H
