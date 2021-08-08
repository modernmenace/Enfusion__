#ifndef ENFUSION_SPRITE_H
#define ENFUSION_SPRITE_H

#include "../Component.h"

class Sprite : public Component {

public:
    explicit Sprite(string_t spriteName = MISSING_TEXTURE);
    explicit Sprite(sf::Texture&);

    void initialize()                     override;
    void render(sf::RenderWindow* window, uint8_t z) override;
    void setVisible(bool v) { s_visible = v; }
    sf::Vector2u center();

    inline void updatePosition(sf::Vector2f p)  { sprite.setPosition(p); }
    inline sf::Sprite& getSprite(){ return sprite; }

private:
    sf::Sprite   sprite;
    string_t     s_name;
    bool s_visible = true;
    sf::Texture* s_tex = nullptr;
};


#endif //ENFUSION_SPRITE_H
