#ifndef ENFUSION_TEXTDISPLAY_H
#define ENFUSION_TEXTDISPLAY_H

#include "../Entity.h"
#include "../../Component/Base/Position.h"

class TextDisplay : public Entity {

public:
    TextDisplay(string_t text, sf::Vector2f position, uint16_t size = 42);

    void initialize() override;
    void render(sf::RenderWindow* window) override;
    void setPosition(sf::Vector2f p);
    inline void setText(string_t t) { text.setString(t); }

private:
    sf::Text text;

    bool textChanged = false;

};


#endif //ENFUSION_TEXTDISPLAY_H
