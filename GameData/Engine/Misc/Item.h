#ifndef ENFUSION___ITEM_H
#define ENFUSION___ITEM_H

#include "../Core/Engine.h"
#include <SFML/Graphics/Sprite.hpp>

//TODO: get rid of flags and store pointer here instead???

enum ItemFlags
{
    IF_NONE,
    IF_REMOVE
};

enum ItemType
{
    Consumable
};

class Item
{
public:
    Item(string_t name, string_t description, string_t icon, ItemType type, uint16_t stackSize);
    inline uint16_t id()          { return i_id;   }
    inline string_t name()        { return i_name; }
    inline string_t description() { return i_desc; }
    inline ItemType type()        { return i_type; }
    inline uint16_t stackSize()   { return i_max;  }
    inline sf::Texture& icon()    { return AssetManager::Instance()->getTexture(i_icon); }

    virtual ItemFlags activate();

private:
    uint16_t    i_id;
    string_t    i_name;
    string_t    i_desc;
    string_t    i_icon;
    uint16_t    i_max;
    ItemType    i_type;
};

#define REGISTRY_ADD(itemClass)            \
ItemRegistry::Instance()->createItem(new itemClass()); \

#define CREATE_ITEM(className, name, description, icon, effect, type, stackSize)   \
class className : public Item                              \
{                                                          \
public :                                                   \
    className()  : Item(name, description, icon, type, stackSize) {};   \
    ItemFlags activate() override { effect Item::activate(); }                       \
};                                                         \


#endif //ENFUSION___ITEM_H
