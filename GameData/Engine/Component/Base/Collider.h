#ifndef ENFUSION___COLLIDER_H
#define ENFUSION___COLLIDER_H

#include "../Component.h"

class Collider : public Component {

public:
    Collider(sf::IntRect, void (*collision)(Entity*));
    bool checkForCollision(sf::IntRect*, Entity*);

private:
    sf::IntRect c_box;
    inline void onCollision(Entity* other) { c_collision(other); }
    void (*c_collision)(Entity*);
};


#endif //ENFUSION___COLLIDER_H
