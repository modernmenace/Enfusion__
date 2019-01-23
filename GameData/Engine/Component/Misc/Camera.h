#ifndef ENFUSION_FOLLOWCAMERA_H
#define ENFUSION_FOLLOWCAMERA_H

#include <memory>
#include "../Component.h"
#include "../Base/Position.h"

enum CameraType
{
    STATIC,
    FOLLOW
};

class Camera : public Component {

public:
    Camera(CameraType type = CameraType::STATIC, Entity* followEntity = nullptr);

    void initialize()                     override;
    void update(sf::Time tickRate)        override;
    void render(sf::RenderWindow *window) override;


private:
    CameraType type;
    Entity     *followEntity = nullptr;

    sf::View* view;
    bool viewSet = false;

    sf::Vector2f centerVec;
    sf::Vector2f sizeVec;
};


#endif //ENFUSION_FOLLOWCAMERA_H
