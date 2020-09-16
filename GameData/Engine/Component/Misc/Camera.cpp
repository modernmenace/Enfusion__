#include <cmath>
#include "Camera.h"
#include "../Base/Position.h"
#include "../../Lvl/LevelManager.h"
#include "../Anim/AnimatedSprite.h"

//todo: finish camera edge collision
//todo: currently issues when spawning with view over edge
//todo: issues getting stuck with camera locked

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

    //todo: calculate initial center vector
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

sf::FloatRect Camera::getPlayerCenteredCameraView()
{
    sf::FloatRect c_view;
    auto p_pos  = entity->getComponent<Position>().getPosition();
    auto p_size = entity->getComponent<AnimatedSprite>().getSprite();

    c_view.left = (p_pos.x+ p_size.getGlobalBounds().width)   - (view->getSize().x / 2);
    c_view.top  = (p_pos.y + p_size.getGlobalBounds().height) - (view->getSize().y / 2);
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
        sf::FloatRect c_v     = getPlayerCenteredCameraView();
        sf::Vector2i l_bounds = LevelManager::Instance()->boundaries();

        sf::Vector2f centerPos;
        centerPos.x = floor(pos.x);          // todo: see note on flooring
        centerPos.y = floor(pos.y + 75); // todo: see note on flooring

        //todo: find out what this magic number 75 is
        if (c_v.left < 75)
        {
            centerPos.x = lastCenter.x;
        }
        if (c_v.top < 75)
        {
            centerPos.y = lastCenter.y;
        }
        if ((c_v.left + c_v.width) > l_bounds.x)
        {
            centerPos.x = lastCenter.x;
        }
        if ((c_v.top + c_v.height) > l_bounds.y)
        {
            centerPos.y = lastCenter.y;
        }
        view->setCenter(centerPos.x, centerPos.y);
        lastCenter.x = centerPos.x;
        lastCenter.y = centerPos.y;
    }
}

void Camera::render(sf::RenderWindow *window)
{
    if (viewSet) return;

    window->setView(*view);

    if (type == CameraType::STATIC)
        viewSet = true;
}