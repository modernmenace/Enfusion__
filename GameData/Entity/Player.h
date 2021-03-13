#ifndef ENFUSION_PLAYER_H
#define ENFUSION_PLAYER_H

#include "../Engine/Entity/Entity.h"
#include "../Engine/Item/Item.h"

typedef struct PlayerEquipment
{
    Item* head   = nullptr;
    Item* top    = nullptr;
    Item* bottom = nullptr;
    Item* weapon = nullptr;
} PlayerEquipment_t;

class Player : public Entity {

public:
    Player(sf::Vector2f position);
    void equipItem(Item*);
    void unequipItem(ItemType);
    void initialize()                          override;
    void handleInput(sf::Mouse::Button button) override;
    sf::FloatRect bounds()                     override;

    PlayerEquipment_t* equipment() { return &p_equipment; }

private:
    PlayerEquipment_t p_equipment;

};


#endif //ENFUSION_PLAYER_H
