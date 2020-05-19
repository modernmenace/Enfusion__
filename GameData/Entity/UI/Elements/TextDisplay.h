#ifndef ENFUSION_TEXTDISPLAY_H
#define ENFUSION_TEXTDISPLAY_H

#include "../../../Engine/Entity/Entity.h"
#include "../../../Engine/Component/Base/Position.h"

class TextDisplay : public Entity {

public:
    TextDisplay(string_t text, sf::Vector2f position,
                uint16_t size = 42,
                sf::RectangleShape bounds = sf::RectangleShape(sf::Vector2f(0, 0)));

    void initialize() override;
    void render(sf::RenderWindow* window) override;
    void setPosition(sf::Vector2f p);
    void setText(string_t t);

    inline sf::Text& text() { return t_text; }

private:
    sf::Text           t_text;
    sf::RectangleShape t_bounds;

    bool textChanged = false;

};


#endif //ENFUSION_TEXTDISPLAY_H
