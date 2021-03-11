#ifndef ENFUSION___ITEM_H
#define ENFUSION___ITEM_H

#include "../Core/Engine.h"
#include <SFML/Graphics/Sprite.hpp>

enum ItemType
{
    Item_Consumable,
    Item_Tool,
    Item_Other
};

class Item
{
public:
    Item(string_t name, string_t description, string_t icon, ItemType type, uint16_t stackSize)
    {
        static uint16_t id = 0;

        this->i_id     = id;
        this->i_name   = name;
        this->i_desc   = description;
        this->i_icon   = icon;
        this->i_max    = stackSize;
        this->i_type   = type;

        id++;
    }

    inline uint16_t  id()            { return i_id;   }
    inline string_t  name()          { return i_name; }
    inline string_t  linkedTexture() { return i_linkedTexture; }
    inline string_t  description()   { return i_desc; }
    inline uint16_t  stackSize()     { return i_max;  }
    inline ItemType type()           { return i_type; }
    inline sf::Texture& icon()       { return AssetManager::Instance()->getTexture(i_icon); }

    inline void setLinkedTexture(string_t s) { i_linkedTexture = s; }

    virtual void activate() {};

private:
    uint16_t    i_id;
    string_t    i_name;
    string_t    i_desc;
    string_t    i_icon;
    uint16_t    i_max;
    ItemType    i_type;

    string_t    i_linkedTexture;
};

#define REGISTRY_ADD(itemClass)                                                    \
ItemRegistry::Instance()->createItem(new itemClass());                             \

#define LINKED_TEXTURE(itemClass, texture)                                         \
ItemRegistry::Instance()->getItem<itemClass>()->setLinkedTexture(texture);         \

#define CREATE_ITEM(className, name, description, icon, effect, type, stackSize)   \
class className : public Item                                                      \
{                                                                                  \
public :                                                                           \
    className()  : Item(name, description, icon, type, stackSize) {};              \
    void activate() override { effect Item::activate(); }                          \
};                                                                                 \


#endif //ENFUSION___ITEM_H
