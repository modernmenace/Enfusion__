#include "Camera.h"

Camera::Camera(CameraType type) : centerVec(0, 0), sizeVec(1920, 1080)
{
    this->type = type;
}

void Camera::initialize()
{
    assert(entity->hasComponent<Position>());
    view = new sf::View(centerVec, sizeVec);
}

void Camera::update(sf::Time tickRate)
{
    if (type == CameraType::FOLLOW)
            view->setCenter(entity->getComponent<Position>().getPosition());
}

void Camera::render(sf::RenderWindow *window)
{
    if (viewSet) return;

    if (type == CameraType::FOLLOW)
    {
        window->setView(*view);
    }
    else if (type == CameraType::STATIC)
    {
        window->setView(*view);
        viewSet = true;
    }
}