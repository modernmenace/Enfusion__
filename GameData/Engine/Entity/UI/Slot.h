#ifndef ENFUSION___SLOT_H
#define ENFUSION___SLOT_H

#include "../../Misc/Item.h"
#include "../../Component/Base/Sprite.h"
#include "../../Component/Base/Position.h"

class Slot : public Entity {

public:
    Slot(sf::Vector2f position, Item* item = nullptr);
    inline Item* item() { return s_item; }
    inline void setItem(Item* item) { s_item = item; }

private:
    Item* s_item;

};


#endif //ENFUSION___SLOT_H
