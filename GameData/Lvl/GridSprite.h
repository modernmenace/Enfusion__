#ifndef ENFUSION___GRIDSPRITE_H
#define ENFUSION___GRIDSPRITE_H

#include "../Engine/Component/Component.h"

class GridSprite : public Component
{
public:
    GridSprite(sf::Texture&);

    void initialize()              override;
    void render(sf::RenderWindow*) override;

    void setVisible(bool v) { s_visible = v; }

private:
    sf::Sprite   sprite;
    string_t     s_name;
    bool         s_visible = true;
    sf::Texture* s_tex     = nullptr;

};


#endif //ENFUSION___GRIDSPRITE_H
