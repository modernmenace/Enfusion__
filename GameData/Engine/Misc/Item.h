#ifndef ENFUSION___ITEM_H
#define ENFUSION___ITEM_H

#include "../Entity/Entity.h"
#include "../Component/Base/Sprite.h"

class Item : public Entity {

public:
    Item(std::string name)
        { Item(name, "", MISSING_TEXTURE, 0); }
    Item(std::string name, std::string sprite)
        { Item(name, "", sprite, 0); }
    Item(std::string name, std::string sprite, uint16_t value)
        { Item(name, "", sprite, value); }
    Item(std::string name, std::string description, std::string sprite, uint16_t value);

    inline std::string name()        { return i_name;  }
    inline std::string description() { return i_desc;  }
    inline uint16_t    value()       { return i_value; }

private:
    std::string i_name;
    std::string i_desc;
    uint16_t    i_value;

};


#endif //ENFUSION___ITEM_H
