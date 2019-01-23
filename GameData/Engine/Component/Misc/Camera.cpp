#include "Camera.h"

Camera::Camera(CameraType type, Entity* followEntity) : centerVec(0, 0), sizeVec(1920, 1080)
{
    this->type         = type;
    this->followEntity = followEntity;

    if ((type == CameraType::FOLLOW) && (followEntity == nullptr))
    {
        dbg_err("Follow camera has no entity to follow, switching to static.")
        this->type = CameraType::STATIC;
    }
}

void Camera::initialize()
{
    view = new sf::View(centerVec, sizeVec);
}

void Camera::update(sf::Time tickRate)
{
    if (type == CameraType::FOLLOW)
    {
        if (followEntity)
        {
            dbg_log("updating follow")
            view->setCenter(followEntity->getComponent<Position>().getPosition());
        }
    }
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