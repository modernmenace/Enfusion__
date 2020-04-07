#ifndef ENFUSION___ITEM_H
#define ENFUSION___ITEM_H

#include "../Core/Engine.h"
#include <SFML/Graphics/Sprite.hpp>

class Item
{
public:
    Item(uint16_t id, string_t name, string_t description, string_t icon);
    inline uint16_t id()          { return i_id; };
    inline string_t name()        { return i_name; };
    inline string_t description() { return i_desc; };
    inline sf::Texture& icon()    { return AssetManager::getTexture(i_icon); };

    virtual void activate();

private:
    uint16_t    i_id;
    string_t    i_name;
    string_t    i_desc;
    string_t    i_icon;
};

#define REGISTRY_ADD(itemClass)            \
ItemRegistry::Instance()->createItem(new itemClass()); \

#define CREATE_ITEM(id, className, name, description, icon, effect)   \
class className : public Item                              \
{                                                          \
public :                                                   \
    className()  : Item(id, name, description, icon) {}    \
    void activate() override effect;                       \
};                                                         \


#endif //ENFUSION___ITEM_H
