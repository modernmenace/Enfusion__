#ifndef ENFUSION___BUTTON_H
#define ENFUSION___BUTTON_H

#include "../Entity.h"
#include "../../Component/Base/Position.h"
#include "../../Component/Base/Sprite.h"
#include "TextDisplay.h"

class Button : public Entity {

public:
    Button(string_t text, sf::Vector2f position) : b_text(text, position)
    {
        addComponent<Position>(sf::Vector2f(position));
        addComponent<Sprite>("UI/windowsheet.png");
        getComponent<Sprite>().getSprite().setTextureRect(sf::IntRect(0, 48, 48, 16));
        getComponent<Sprite>().getSprite().setScale(5, 5);

    }
    void initialize() override
    {
        b_text.initialize();
        Entity::initialize();
    }

    void render(sf::RenderWindow* window) override
    {
        Entity::render(window);
        b_text.render(window);
    }


private:
    TextDisplay b_text;

};


#endif //ENFUSION___BUTTON_H