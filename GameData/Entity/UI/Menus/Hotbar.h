#ifndef ENFUSION___HOTBAR_H
#define ENFUSION___HOTBAR_H

#include "../../../Engine/Entity/Entity.h"
#include "../Elements/TextDisplay.h"
#include "../Elements/Slot.h"
#include "InventoryMenu.h"

#define HOTBAR_SLOTS 6

class Hotbar : public Entity {

public:
    Hotbar(Entity* entity, sf::Vector2f position, InventoryMenu* menu);
    ~Hotbar()         override;
    void initialize() override;
    void render(sf::RenderWindow* window)   override;
    void handleInput(sf::Keyboard::Key)     override;
    void handleInput(sf::Mouse::Button)     override;

    void updateSlots();

private:
    std::vector<Slot*>  slots;
    sf::RectangleShape selectionRect;


    Entity*        i_entity = nullptr;
    Inventory*     i_i      = nullptr;
    InventoryMenu* i_menu   = nullptr;
    TextDisplay*   h_text   = nullptr;
};


#endif //ENFUSION___HOTBAR_H
