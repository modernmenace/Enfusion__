#ifndef ENFUSION___TOOLTIP_H
#define ENFUSION___TOOLTIP_H

#include "../Entity.h"
#include "../../Component/Base/Position.h"
#include "../../Component/Base/Sprite.h"
#include "../../Misc/Item.h"
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
