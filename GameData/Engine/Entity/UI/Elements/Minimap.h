#ifndef ENFUSION___MINIMAP_H
#define ENFUSION___MINIMAP_H

#include "../../Entity.h"
#include "../../../Component/Base/Position.h"
#include "../../../Component/Base/Sprite.h"

class Minimap : public Entity {

public:
    Minimap();
    void initialize() override;
    void render(sf::RenderWindow*);


private:
    sf::View m_view;

};


#endif //ENFUSION___MINIMAP_H
