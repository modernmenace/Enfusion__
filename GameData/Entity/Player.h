#ifndef ENFUSION_PLAYER_H
#define ENFUSION_PLAYER_H

#include "../Engine/Entity/Entity.h"
#include "../Engine/Item/Item.h"

typedef struct PlayerEquipment
{
    bool head   = false;
    bool top    = false;
    bool bottom = false;
    bool weapon = false;
    
    WeaponStats_t   weapon_stats;
    ClothingStats_t head_stats;
    ClothingStats_t top_stats;
    ClothingStats_t bottom_stats;

} PlayerEquipment_t;

class Player : public Entity {

public:
    Player(sf::Vector2f position);
    void equipItem(Item*);
    void unequipItem(ItemType);
    void handleInput(sf::Mouse::Button button) override;
    sf::FloatRect bounds()                     override;



private:
    PlayerEquipment_t p_equipment;

};


#endif //ENFUSION_PLAYER_H
