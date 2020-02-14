#ifndef ENFUSION___ITEM_H
#define ENFUSION___ITEM_H

#include "../Core/Engine.h"
#include <SFML/Graphics/Sprite.hpp>

class ItemEffect;

class Item
{
public:
    Item(string_t name, string_t description, string_t icon, ItemEffect* effect = nullptr);
    inline uint16_t id()          { return i_id; };
    inline string_t name()        { return i_name; };
    inline string_t description() { return i_desc; };
    inline sf::Texture& icon()    { return AssetManager::getTexture(i_icon); };

    void activate();

private:
    uint16_t    i_id;
    string_t    i_name;
    string_t    i_desc;
    string_t    i_icon;
    ItemEffect* i_effect = nullptr;
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
