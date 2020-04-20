#ifndef ENFUSION___DROPBOX_H
#define ENFUSION___DROPBOX_H

#include "../../Entity.h"
#include "../../../Component/Base/Position.h"
#include "../../../Component/Base/Sprite.h"

class DropBox : public Entity
{

public:
    DropBox(sf::Vector2f position)
    {
        addComponent<Position>(position);
        addComponent<Sprite>("UI/dropbox.png");
        getComponent<Sprite>().getSprite().setScale(4, 4);
    }

private:


};



#endif //ENFUSION___DROPBOX_H
