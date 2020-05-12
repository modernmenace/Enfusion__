#ifndef ENFUSION___TOOLTIP_H
#define ENFUSION___TOOLTIP_H

#include "../../../Engine/Entity/Entity.h"
#include "../../../Engine/Component/Base/Position.h"
#include "../../../Engine/Component/Base/Sprite.h"
#include "../../../Engine/Item/Item.h"
#include "TextDisplay.h"

class Tooltip : public Entity {

public:
    Tooltip();
    void initialize()              override;
    void render(sf::RenderWindow*) override;
    void show(Item* item, sf::Vector2f position);
    inline void hide() { t_visible = false; };

private:
    TextDisplay t_iName;
    TextDisplay t_iDesc;

    bool t_visible = false;

};


#endif //ENFUSION___TOOLTIP_H
