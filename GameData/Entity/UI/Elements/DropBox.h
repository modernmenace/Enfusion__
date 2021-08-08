#ifndef ENFUSION___DROPBOX_H
#define ENFUSION___DROPBOX_H

#include "../../../Engine/Entity/Entity.h"
#include "../../../Engine/Component/Base/Position.h"
#include "../../../Engine/Component/Base/Sprite.h"

class DropBox : public Entity
{

public:
    DropBox(sf::Vector2f position) : d_text("", sf::Vector2f(0, 0), 30)
    {
        addComponent<Position>(position);
        addComponent<Sprite>("UI/ui.png");
        getComponent<Sprite>().getSprite()->setTextureRect(sf::IntRect(0, 64, 90, 16));
        getComponent<Sprite>().getSprite()->setScale(4, 4);
    }

    void initialize() override
    {
        Entity::initialize();
        d_text.initialize();
        d_text.setText(std::to_string(WINDOW_WIDTH) + "x" + std::to_string(WINDOW_HEIGHT));
        d_text.setPosition(sf::Vector2f(getComponent<Position>().getPosition().x + ((getComponent<Sprite>().getSprite()->getGlobalBounds().width / 2)-25) - (d_text.text().getGlobalBounds().width / 2),
                                        getComponent<Position>().getPosition().y+12));
    }

    void render(sf::RenderWindow* window) override
    {
        Entity::render(window);
        d_text.render(window);
    }

private:
    TextDisplay d_text;

};



#endif //ENFUSION___DROPBOX_H
