#ifndef ENFUSION___COLLIDER_H
#define ENFUSION___COLLIDER_H

#include "../Component.h"

class Collider : public Component {

public:
    Collider(sf::FloatRect, void (*collision)(Entity*));
    inline void checkForCollision(Entity* other) { if ( other->bounds().intersects(c_box)) onCollision(other); };

private:
    sf::FloatRect c_box;
    inline void onCollision(Entity* other) { c_collision(other); }
    void (*c_collision)(Entity*);
};


#endif //ENFUSION___COLLIDER_H
