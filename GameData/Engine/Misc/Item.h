#ifndef ENFUSION___ITEM_H
#define ENFUSION___ITEM_H

#include "../Core/Engine.h"

class Item {

public:
    Item(std::string name)                                 { Item(name, "", MISSING_TEXTURE, 0); }
    Item(std::string name, std::string sprite)             { Item(name, "", sprite, 0); }
    Item(std::string name, std::string sprite, uint value) { Item(name, "", sprite, value); }

    Item(std::string name, std::string description, std::string sprite, uint value);

private:


};


#endif //ENFUSION___ITEM_H
