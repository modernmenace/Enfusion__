#include <cmath>
#include "Camera.h"
#include "../Base/Position.h"
#include "../../Lvl/LevelManager.h"
#include "../Anim/AnimatedSprite.h"

/************************************************************************
 * FUNCTION :       Camera::Camera
 *
 * DESCRIPTION :
 *       Constructor, set the camera type
 *
 *  INPUTS:  CameraType type : type of camera
 *
 *  OUTPUTS: NONE
 *
 *  VERSION   	DATE    		WHO     DETAIL
 *  V1.00.00   	2021.01.06 	    JCB     Documentation Start
 *
 ************************************************************************/

Camera::Camera(CameraType type) : centerVec(0, 0), sizeVec(1920, 1080)
{
    this->type = type;
}
/************************************************************************
 * FUNCTION :       Camera::~Camera
 *
 * DESCRIPTION :
 *       Destructor, cleanup
 *
 *  INPUTS:  NONE
 *
 *  OUTPUTS: NONE
 *
 *  VERSION   	DATE    		WHO     DETAIL
 *  V1.00.00   	2021.01.06 	    JCB     Documentation Start
 *
 ************************************************************************/

Camera::~Camera()
{
    delete view;
}

/************************************************************************
 * FUNCTION :       Camera::initialize
 *
 * DESCRIPTION :
 *       Sets up the view
 *
 *  INPUTS:  NONE
 *
 *  OUTPUTS: NONE
 *
 *  VERSION   	DATE    		WHO     DETAIL
 *  V1.00.00   	2021.01.06 	    JCB     Documentation Start
 *
 ************************************************************************/

void Camera::initialize()
{
    if (type == CameraType::FOLLOW)
        assert(entity->hasComponent<Position>());

    view = new sf::View(centerVec, sizeVec);
}

/************************************************************************
 * FUNCTION :       Camera::getCameraView
 *
 * DESCRIPTION :
 *       Returns the current view
 *
 *  INPUTS:  NONE
 *
 *  OUTPUTS: sf::FloatRect : the current camera view
 *
 *  VERSION   	DATE    		WHO     DETAIL
 *  V1.00.00   	2021.01.06 	    JCB     Documentation Start
 *
 ************************************************************************/

sf::FloatRect Camera::getCameraView()
{
    sf::FloatRect c_view;
    c_view.left   = view->getCenter().x - (view->getSize().x / 2);
    c_view.top    = view->getCenter().y - (view->getSize().y / 2);
    c_view.width  = view->getSize().x;
    c_view.height = view->getSize().y;
    return c_view;
}

/************************************************************************
 * FUNCTION :       Camera::getPlayerCenteredCameraView
 *
 * DESCRIPTION :
 *       Returns a view centered on the player
 *
 *  INPUTS:  NONE
 *
 *  OUTPUTS: sf::FloatRect : player-centered camera view
 *
 *  VERSION   	DATE    		WHO     DETAIL
 *  V1.00.00   	2021.01.06 	    JCB     Documentation Start
 *
 ************************************************************************/

sf::FloatRect Camera::getPlayerCenteredCameraView()
{
    sf::FloatRect c_view;
    auto p_pos  = entity->getComponent<Position>().getPosition();
    auto p_size = entity->getComponent<AnimatedSprite>().getSprite();

    c_view.left = (p_pos.x+ p_size->getGlobalBounds().width)   - (view->getSize().x / 2);
    c_view.top  = (p_pos.y + p_size->getGlobalBounds().height) - (view->getSize().y / 2);
    c_view.width  = view->getSize().x;
    c_view.height = view->getSize().y;

    return c_view;
}

/************************************************************************
 * FUNCTION :       Camera::update
 *
 * DESCRIPTION :
 *       Updates the camera position + view based on type
 *
 *  INPUTS:  sf::Time tickRate : the current tick rate
 *
 *  OUTPUTS: NONE
 *
 *  VERSION   	DATE    		WHO     DETAIL
 *  V1.00.00   	2021.01.06 	    JCB     Documentation Start
 *
 ************************************************************************/

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

        //fix issues caused by spawning over the edge
        if (!c_hasVerifiedSpawnView)
        {
            if (c_v.top < 75)
            {
                centerPos.y -= (c_v.top - 75);
            }
            if (c_v.left < 78)
            {
                centerPos.x -= (c_v.left - 78);
            }
            if ((c_v.left + c_v.width) > l_bounds.x)
            {
                centerPos.x = l_bounds.x - c_v.width + (c_v.width / 2);
            }
            if ((c_v.top + c_v.height) > l_bounds.y)
            {
                centerPos.y = l_bounds.y - c_v.height + (c_v.height / 2);
            }

            c_hasVerifiedSpawnView = true;
            view->setCenter(centerPos.x, centerPos.y);
            lastCenter.x = centerPos.x;
            lastCenter.y = centerPos.y;
            return;
        }

        if (c_v.left < 78)
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

/************************************************************************
 * FUNCTION :       Camera::render
 *
 * DESCRIPTION :
 *       Sets the camera view if not yet set
 *
 *  INPUTS:  sf::RednerWindow *window : the current window
 *
 *  OUTPUTS: NONE
 *
 *  VERSION   	DATE    		WHO     DETAIL
 *  V1.00.00   	2021.01.06 	    JCB     Documentation Start
 *
 ************************************************************************/

void Camera::render(sf::RenderWindow *window, uint8_t z)
{
    if (viewSet) return;

    window->setView(*view);

    if (type == CameraType::STATIC)
        viewSet = true;
}