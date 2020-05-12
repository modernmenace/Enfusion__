#ifndef ENFUSION___ITEMPICKUP_H
#define ENFUSION___ITEMPICKUP_H

#include "../../Engine/Entity/Entity.h"
#include "../../Engine/Item/Item.h"

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
