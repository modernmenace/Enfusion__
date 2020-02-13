#ifndef ENFUSION___ITEM_H
#define ENFUSION___ITEM_H

#include "../Core/Engine.h"
#include <SFML/Graphics/Sprite.hpp>

class ItemEffect;

// TODO: Was trying to avoid it, but this may turn into a class
struct Item
{
    uint16_t    id;
    string_t    name;
    string_t    description;
    sf::Sprite  icon;
    ItemEffect* effect = nullptr;
    uint16_t    count;
};

class ItemEffect
{
public:
    ItemEffect(Item* it);
    virtual void onUse();

private:
    Item* item = nullptr;
};

#define IE_CREATE(effName)        \
class effName : public ItemEffect \
{                                 \
public:                           \
    void onUse() override;        \
};                                \

#define IE_ONUSE(effName, body)   \
void effName::onUse() body        \

#endif //ENFUSION___ITEM_H
