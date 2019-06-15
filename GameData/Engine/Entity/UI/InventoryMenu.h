#ifndef ENFUSION___INVENTORYMENU_H
#define ENFUSION___INVENTORYMENU_H

#include "../Entity.h"
#include "../../Component/Misc/Inventory.h"

class InventoryMenu : public Entity {

public:
    InventoryMenu(Entity* entity);
    void initialize() override;
    void handleInput(sf::Keyboard::Key key) override;
    void toggleMenu();

private:
    Entity* i_entity = nullptr;

};


#endif //ENFUSION___INVENTORYMENU_H
