#ifndef ENFUSION_TEXTDISPLAY_H
#define ENFUSION_TEXTDISPLAY_H

#include "../Entity.h"
#include "../../Component/Base/Position.h"

class TextDisplay : public Entity {

public:
    TextDisplay(std::string text, sf::Vector2f position, uint size = 42);

    void initialize() override;
    void render(sf::RenderWindow* window) override;

    void setText(std::string text);


private:
    sf::Text text;

    bool textChanged = false;

};


#endif //ENFUSION_TEXTDISPLAY_H
