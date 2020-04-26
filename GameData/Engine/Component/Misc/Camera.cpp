#include <cmath>
#include "Camera.h"

Camera::Camera(CameraType type) : centerVec(0, 0), sizeVec(1920, 1080)
{
    this->type = type;
}

Camera::~Camera()
{
    delete view;
}

void Camera::initialize()
{
    if (type == CameraType::FOLLOW)
        assert(entity->hasComponent<Position>());

    view = new sf::View(centerVec, sizeVec);
}

//NOTE: Flooring view values fixes flickering of tile map, however player sprite looks shakey
void Camera::update(sf::Time tickRate)
{
    auto pos = entity->getComponent<Position>().getPosition();
    if (type == CameraType::FOLLOW)
            view->setCenter(floor(pos.x), floor(pos.y)+75);
}

void Camera::render(sf::RenderWindow *window)
{
    if (viewSet) return;

    window->setView(*view);

    if (type == CameraType::STATIC)
        viewSet = true;
}