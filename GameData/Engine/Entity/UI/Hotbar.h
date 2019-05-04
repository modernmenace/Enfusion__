#ifndef ENFUSION___HOTBAR_H
#define ENFUSION___HOTBAR_H

#include "../Entity.h"
#include "../../Component/Base/Sprite.h"
#include "../../Component/Base/Position.h"

class Hotbar : public Entity {

public:
    Hotbar(sf::Vector2f position);
    void initialize() override;


};


#endif //ENFUSION___HOTBAR_H
