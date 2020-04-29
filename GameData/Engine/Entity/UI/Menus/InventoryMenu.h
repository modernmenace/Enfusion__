#ifndef ENFUSION___INVENTORYMENU_H
#define ENFUSION___INVENTORYMENU_H

#include "../../Entity.h"
#include "../Elements/Slot.h"
#include "../Elements/Tooltip.h"

#define DRAG_THRESHOLD_S 0.1

class InventoryMenu : public Entity {

public:
    InventoryMenu(Entity* entity);
    ~InventoryMenu()  override;
    void initialize() override;
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

    bool        i_mouseDown    = false;
    bool        i_drag         = false;
    int         i_dragIndex;
    sf::Clock   i_mouseClock;
    Tooltip     i_tooltip;

};


#endif //ENFUSION___INVENTORYMENU_H
