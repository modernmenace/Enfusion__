#include "Tooltip.h"

/************************************************************************
 * FUNCTION :       Tooltip::Tooltip
 *
 * DESCRIPTION :
 *       Constructor, set up components
 *
 *  INPUTS:  NONE
 *
 *  OUTPUTS: NONE
 *
 *  VERSION   	DATE    		WHO     DETAIL
 *  V1.00.00   	2021.03.10 	    JCB     Documentation Start
 *
 ************************************************************************/

Tooltip::Tooltip() : t_iName("", sf::Vector2f(0, 0), 20),
                     t_iDesc("", sf::Vector2f(0, 0), 15, sf::RectangleShape(sf::Vector2f(48, 48))),
                     t_iType("Test", sf::Vector2f(0, 0), 10)
{
    addComponent<Position>(sf::Vector2f(0, -0));
    addComponent<Sprite>("UI/ui.png");
}

/************************************************************************
 * FUNCTION :       Tooltip::initialize
 *
 * DESCRIPTION :
 *       Initialize sprites and textdisplays
 *
 *  INPUTS:  NONE
 *
 *  OUTPUTS: NONE
 *
 *  VERSION   	DATE    		WHO     DETAIL
 *  V1.00.00   	2021.03.10 	    JCB     Documentation Start
 *
 ************************************************************************/

void Tooltip::initialize()
{
    getComponent<Sprite>().getSprite().setTextureRect(sf::IntRect(0, 0, 48, 48));
    getComponent<Sprite>().getSprite().setScale(4, 4);

    t_iName.initialize();
    t_iDesc.initialize();
    t_iType.initialize();
}

/************************************************************************
 * FUNCTION :       Tooltip::show
 *
 * DESCRIPTION :
 *       Update the tooltip with the correct information and display it
 *
 *  INPUTS:  Item* item             |  The item to be displayed
 *           sf::Vector2f position  |  The position of the window
 *
 *  OUTPUTS: NONE
 *
 *  VERSION   	DATE    		WHO     DETAIL
 *  V1.00.00   	2021.03.10 	    JCB     Documentation Start
 *
 ************************************************************************/

void Tooltip::show(Item* item, sf::Vector2f position)
{
    if (currentItem == item)
        return;

    currentItem = item;
    getComponent<Position>().setPosition(position);
    getComponent<Sprite>().getSprite().setPosition(position);
    getComponent<Sprite>().setVisible(true);

    t_iName.setText(item->name());
    t_iDesc.setText(item->description());
    t_iType.setColor(sf::Color::Magenta);

    sf::Vector2f pos = getComponent<Position>().getPosition();

    switch (item->type())
    {
        case Item_Consumable:
            t_iType.setText("Consumable");
            pos.x += 125;
            pos.y += 12;
            t_iType.setPosition(pos);
            break;
        case Item_Weapon:
            t_iType.setText("Weapon");
            pos.x += 145;
            pos.y += 12;
            t_iType.setPosition(pos);
            break;
        default:
            t_iType.setText("Unknown");
            pos.x += 130;
            pos.y += 12;
            t_iType.setPosition(pos);
            break;
    }

    pos = getComponent<Position>().getPosition();
    pos.x += 15;
    pos.y += 10;
    t_iName.setPosition(pos);
    pos.y += 30;
    t_iDesc.setPosition(pos);

    t_visible = true;
}

/************************************************************************
 * FUNCTION :       Tooltip::render
 *
 * DESCRIPTION :
 *       Render the tooltip window
 *
 *  INPUTS:  sf::RenderWindow* window  | The window to render to
 *
 *  OUTPUTS: NONE
 *
 *  VERSION   	DATE    		WHO     DETAIL
 *  V1.00.00   	2021.03.10 	    JCB     Documentation Start
 *
 ************************************************************************/

void Tooltip::render(sf::RenderWindow* window)
{
    if (!t_visible) return;
    Entity::render(window);

    t_iName.render(window);
    t_iDesc.render(window);
    t_iType.render(window);
}