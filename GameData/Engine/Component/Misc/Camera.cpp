#include <cmath>
#include "Camera.h"
#include "../Base/Position.h"
#include "../../Lvl/LevelManager.h"

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

sf::FloatRect Camera::getCameraView()
{
    sf::FloatRect c_view;
    c_view.left   = view->getCenter().x - (view->getSize().x / 2);
    c_view.top    = view->getCenter().y - (view->getSize().y / 2);
    c_view.width  = view->getSize().x;
    c_view.height = view->getSize().y;
    return c_view;
}

//TODO: On lower resolutions DO NOT FLOOR, causes flickering rather than preventing it
//TODO: Revisit this once resolutions are implemented
//NOTE: Flooring view values fixes flickering of tile map, however player sprite looks shakey
void Camera::update(sf::Time tickRate)
{
    auto pos = entity->getComponent<Position>().getPosition();
    if (type == CameraType::FOLLOW)
    {
        //check for edge collision
        sf::FloatRect c_v = getCameraView();
        sf::Vector2i l_bounds = LevelManager::Instance()->boundaries();

        sf::Vector2f centerPos;
        centerPos.x = floor(pos.x);          // todo: see note on flooring
        centerPos.y = floor(pos.y + 75); // todo: see note on flooring

        //todo: implement this
        if (c_v.left < 0) {
            dbg_log("hit left edge")
        }
        if (c_v.top < 0) {
            dbg_log("hit top edge")
        }
        if ((c_v.left + c_v.width) > l_bounds.x) {
            dbg_log("hit right edge")
        }
        if ((c_v.top + c_v.height) > l_bounds.y) {
            dbg_log("hit bottom edge")
        }
        view->setCenter(centerPos.x, centerPos.y);
    }
}

void Camera::render(sf::RenderWindow *window)
{
    if (viewSet) return;

    window->setView(*view);

    if (type == CameraType::STATIC)
        viewSet = true;
}