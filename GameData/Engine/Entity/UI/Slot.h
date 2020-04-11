#ifndef ENFUSION___SLOT_H
#define ENFUSION___SLOT_H

#include "../../Misc/Item.h"
#include "../../Component/Base/Sprite.h"
#include "../../Component/Base/Position.h"

class Slot : public Entity {

public:
    Slot(sf::Vector2f position, Item* item = nullptr);
    void render(sf::RenderWindow *window) override;
    void setItem(Item* item);
    inline void setVisible(bool v) { s_visible = v; };
    inline Item* item() { return s_item; }

private:
    Item*      s_item;
    sf::Sprite s_sprite;
    bool       s_visible = true;

};


#endif //ENFUSION___SLOT_H
