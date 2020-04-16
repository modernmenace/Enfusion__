#ifndef ENFUSION___INVENTORYMENU_H
#define ENFUSION___INVENTORYMENU_H

#include "../Entity.h"
#include "../../Component/Base/Sprite.h"
#include "../../Component/Base/Position.h"
#include "../../Component/Misc/Inventory.h"
#include "Slot.h"
#include "Tooltip.h"

//TODO: Remove this after testing
#include "../../Misc/ItemRegistry.h"
#include "../../../Data/Items.h"

class InventoryMenu : public Entity {

public:
    InventoryMenu(Entity* entity);
    ~InventoryMenu()  override;
    void initialize() override;
    void handleInput(sf::Keyboard::Key key) override;
    void handleInput(sf::Mouse::Button)     override;
    void update(sf::Time tickRate)          override;
    void render(sf::RenderWindow* window)   override;
    void toggleMenu();
    void updateSlots();
    inline bool active() { return menuActive; };
    std::vector<Slot*>  slots;

private:
    Entity* i_entity = nullptr;
    bool menuActive  = false;

    Tooltip i_tooltip;

};


#endif //ENFUSION___INVENTORYMENU_H
