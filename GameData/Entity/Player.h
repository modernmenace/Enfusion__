#ifndef ENFUSION_PLAYER_H
#define ENFUSION_PLAYER_H

#include "../Engine/Entity/Entity.h"
#include "../Engine/Item/Item.h"

class Player : public Entity {

public:
    Player(sf::Vector2f position);
    void equipItem(Item*);
    void unequipItem(ItemType);
    void handleInput(sf::Mouse::Button button) override;
    sf::FloatRect bounds()                     override;



private:


};


#endif //ENFUSION_PLAYER_H
