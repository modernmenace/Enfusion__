#ifndef ENFUSION___COLLIDER_H
#define ENFUSION___COLLIDER_H

#include "../Component.h"

class Collider : public Component {

public:
    Collider(sf::FloatRect r) { c_box = r; };
    inline bool checkForCollision(Entity* e) { return e->bounds().intersects(c_box); };

private:
    sf::FloatRect c_box;
};


#endif //ENFUSION___COLLIDER_H
