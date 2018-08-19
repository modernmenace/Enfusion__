#ifndef ENFUSION_SPRITE_H
#define ENFUSION_SPRITE_H

#include "../Component.h"

INITIALIZE_COMPONENT
class Sprite : public Component {

public:
    Sprite(std::string spriteName = MISSING_TEXTURE);

    void initialize() override;
    void render(sf::RenderWindow* window) override;

private:
    sf::Sprite sprite;
    std::string spriteName;

};


#endif //ENFUSION_SPRITE_H
