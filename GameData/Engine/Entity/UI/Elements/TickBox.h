#ifndef ENFUSION___TICKBOX_H
#define ENFUSION___TICKBOX_H

#include "../../Entity.h"
#include "../../../Component/Base/Position.h"
#include "../../../Component/Base/Sprite.h"

class TickBox : public Entity {

public:
    TickBox(sf::Vector2f position)
    {
        addComponent<Position>(position);
        addComponent<Sprite>("UI/ui.png");
        getComponent<Sprite>().getSprite().setTextureRect(sf::IntRect(48, 0, 18, 16));
        getComponent<Sprite>().getSprite().setScale(5, 5);
    }

    void set(bool status)
    {
        t_status = status;
        if (t_status)
            getComponent<Sprite>().getSprite().setTextureRect(sf::IntRect(48, 17, 18, 16));
        else
            getComponent<Sprite>().getSprite().setTextureRect(sf::IntRect(48, 0, 18, 16));
    }
    inline bool get()            { return t_status;   }

private:
    bool t_status = false;

};




#endif //ENFUSION___TICKBOX_H
