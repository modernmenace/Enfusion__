#ifndef ENFUSION___TOOLTIP_H
#define ENFUSION___TOOLTIP_H

#include "../Entity.h"
#include "../../Component/Base/Position.h"
#include "../../Component/Base/Sprite.h"
#include "../../Misc/Item.h"

class Tooltip : public Entity {

public:
    Tooltip();
    void initialize() override;
    void show(Item* item, sf::Vector2f position);
    inline void hide() { getComponent<Sprite>().visible = false; }

};


#endif //ENFUSION___TOOLTIP_H
