#ifndef ENFUSION_FOLLOWCAMERA_H
#define ENFUSION_FOLLOWCAMERA_H

#include "../Component.h"

enum CameraType
{
    STATIC,
    FOLLOW
};

class Camera : public Component {

public:
    Camera(CameraType type = CameraType::STATIC);
    ~Camera();

    void initialize()                     override;
    void update(sf::Time tickRate)        override;
    void render(sf::RenderWindow *window) override;

    sf::FloatRect getCameraView();
    sf::FloatRect getPlayerCenteredCameraView();

private:
    CameraType type;

    sf::View* view;
    bool viewSet = false;

    sf::Vector2f centerVec;
    sf::Vector2f sizeVec;

    sf::Vector2f lastCenter;
};


#endif //ENFUSION_FOLLOWCAMERA_H
