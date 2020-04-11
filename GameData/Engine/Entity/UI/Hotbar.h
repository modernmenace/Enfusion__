#ifndef ENFUSION___HOTBAR_H
#define ENFUSION___HOTBAR_H

#include "../Entity.h"
#include "../../Component/Base/Sprite.h"
#include "../../Component/Base/Position.h"
#include "../../Component/Misc/Inventory.h"
#include "TextDisplay.h"
#include "Slot.h"
#include "InventoryMenu.h"

#define HOTBAR_SLOTS 6

class Hotbar : public Entity {

public:
    Hotbar(Entity* entity, sf::Vector2f position, InventoryMenu* menu);
    void initialize() override;
    void render(sf::RenderWindow* window) override;
    void handleInput(sf::Keyboard::Key key) override;

    void updateSlots();

private:
    std::vector<Slot*>  slots;
    sf::RectangleShape selectionRect;
    InventoryMenu*     i_menu;
    uint8_t            selectedSlot = 0;


    Entity* i_entity      = nullptr;
    TextDisplay* itemText = nullptr;
};


#endif //ENFUSION___HOTBAR_H
