#ifndef ENFUSION___SLOT_H
#define ENFUSION___SLOT_H

#include "../../Misc/Item.h"
#include "../../Component/Base/Sprite.h"
#include "../../Component/Base/Position.h"
#include "TextDisplay.h"

class Slot : public Entity {

public:
    Slot(sf::Vector2f position, Item* item = nullptr);
    void render(sf::RenderWindow *window) override;
    void setItem(Item* item);
    void setCount(int c);
    inline bool visible() { return s_visible; }
    inline int  count()   { return s_amount; }
    inline Item* item()   { return s_item; }
    inline void setVisible(bool v) { s_visible = v; };

private:
    Item*      s_item;
    sf::Sprite s_sprite;
    bool       s_visible = true;
    int        s_amount;

    TextDisplay s_text;
};


#endif //ENFUSION___SLOT_H
