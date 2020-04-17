#ifndef ENFUSION___SLOT_H
#define ENFUSION___SLOT_H

#include "../../Misc/Item.h"
#include "../../Component/Base/Sprite.h"
#include "../../Component/Base/Position.h"
#include "TextDisplay.h"
#include "../../Component/Misc/Inventory.h"

class Slot : public Entity {

public:
    Slot(sf::Vector2f position, Inventory* inv, Item* item = nullptr);
    void render(sf::RenderWindow *window) override;
    void setItem(Item* item);
    void setCount(int c);
    void activateItem();
    inline bool visible() { return s_visible; }
    inline int  count()   { return s_amount; }
    inline Item* item()   { return s_item; }
    inline void setVisible(bool v) { s_visible = v; };

    inline sf::Sprite* itemSprite() { return &s_sprite; };

private:
    Item*       s_item;
    Inventory*  s_inv = nullptr;
    TextDisplay s_text;
    sf::Sprite  s_sprite;
    bool        s_visible = true;
    int         s_amount;
};


#endif //ENFUSION___SLOT_H
