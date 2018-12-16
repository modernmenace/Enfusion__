#ifndef ENFUSION_FOLLOWCAMERA_H
#define ENFUSION_FOLLOWCAMERA_H

#include "../Component.h"

class Camera : public Component {

public:
    Camera();

    void initialize()              override;
    void update(sf::Time tickRate) override;

};


#endif //ENFUSION_FOLLOWCAMERA_H
