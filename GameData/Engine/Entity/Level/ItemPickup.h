#ifndef ENFUSION___ITEMPICKUP_H
#define ENFUSION___ITEMPICKUP_H

#include "../Entity.h"
#include "../../Misc/Item.h"

class ItemPickup : public Entity {

public:
    ItemPickup(Item* item, uint8_t count = 1);
    void handleInput(sf::Keyboard::Key) override;

private:
    void create();
    void pickup();

    Item*   p_item  = nullptr;
    uint8_t p_count;
};


#endif //ENFUSION___ITEMPICKUP_H
