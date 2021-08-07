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

    inline PlayerEquipment_t* equipment() { return &p_equipment; }
    inline uint8_t z() { return p_z; }

    sf::FloatRect getView(sf::Time tickRate);

private:
    PlayerEquipment_t p_equipment;

    uint8_t p_z = (Z_TOP / 2); // Allow room for things above and below

    sf::FloatRect v_lastView;
    sf::Time      v_lastTick;
};


#endif //ENFUSION_PLAYER_H
