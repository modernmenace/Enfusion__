#ifndef ENFUSION_SPRITE_H
#define ENFUSION_SPRITE_H

#include "../Component.h"

class Sprite : public Component {

public:
    void initialize() override;
    void update() override;
    void render(sf::RenderWindow* window) override;

};


#endif //ENFUSION_SPRITE_H
