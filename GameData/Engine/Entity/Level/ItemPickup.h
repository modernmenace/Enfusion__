#ifndef ENFUSION___ITEMPICKUP_H
#define ENFUSION___ITEMPICKUP_H

#include "../Entity.h"
#include "../../Misc/Item.h"

class ItemPickup : public Entity {

public:
    ItemPickup(Item* item);
    void update(sf::Time) override;

private:
    void create();
    static void collision(Entity*);

    Item*  p_item = nullptr;
};


#endif //ENFUSION___ITEMPICKUP_H
