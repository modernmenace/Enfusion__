#ifndef ENFUSION___HOTBAR_H
#define ENFUSION___HOTBAR_H

#include "../Entity.h"
#include "../../Component/Base/Sprite.h"
#include "../../Component/Base/Position.h"

#define HOTBAR_SLOTS 6

struct Slot
{
    sf::Sprite sprite;
};

class Hotbar : public Entity {

public:
    Hotbar(sf::Vector2f position);
    void initialize() override;
    void render(sf::RenderWindow* window) override;
    void handleInput(sf::Keyboard::Key key);

private:
    std::vector<Slot> slots;
    int selectedSlot = 0;
    sf::RectangleShape selectionRect;

};


#endif //ENFUSION___HOTBAR_H
