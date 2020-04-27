#ifndef ENFUSION___MINIMAP_H
#define ENFUSION___MINIMAP_H

#include "../../Entity.h"
#include "../../../Component/Base/Position.h"
#include "../../../Component/Base/Sprite.h"
#include "../../../Lvl/Level.h"

class Minimap : public Entity {

public:
    Minimap(Entity* centerEntity, Level* level);
    void initialize() override;
    void render(sf::RenderWindow*);


private:
    sf::View m_view;
    Entity*  m_center = nullptr;
    Level*   m_level  = nullptr;

};


#endif //ENFUSION___MINIMAP_H
