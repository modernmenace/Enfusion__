#ifndef ENFUSION___INVENTORYMENU_H
#define ENFUSION___INVENTORYMENU_H

#include "../Entity.h"
#include "../../Component/Base/Sprite.h"
#include "../../Component/Base/Position.h"
#include "../../Component/Misc/Inventory.h"
#include "Slot.h"

class InventoryMenu : public Entity {

public:
    InventoryMenu(Entity* entity);
    void initialize() override;
    void handleInput(sf::Keyboard::Key key) override;
    void render(sf::RenderWindow* window)   override;
    void toggleMenu();
    inline bool active() { return menuActive; };
    std::vector<Slot*>  slots;

private:
    Entity* i_entity = nullptr;
    bool menuActive  = false;

};


#endif //ENFUSION___INVENTORYMENU_H
