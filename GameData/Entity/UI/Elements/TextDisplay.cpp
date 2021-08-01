#include <cmath>
#include "TextDisplay.h"

/************************************************************************
 * FUNCTION :       TextDisplay::TextDisplay
 *
 * DESCRIPTION :
 *       Constructor, set up components
 *
 *  INPUTS:  string_t text              |  Text to be displayed
 *           sf::Vector2f position      |  Starting position (top-left corner)
 *           uint16_t size              |  Character size
 *           sf::RectangleShape bounds  |  Bounds for the text
 *
 *  OUTPUTS: NONE
 *
 *  VERSION   	DATE    		WHO     DETAIL
 *  V1.00.00   	2021.03.10 	    JCB     Documentation Start
 *
 ************************************************************************/

TextDisplay::TextDisplay(string_t text, sf::Vector2f position, uint16_t size, sf::RectangleShape bounds)
{
    t_bounds = bounds;
    t_text.setString(text);
    t_text.setCharacterSize(size);
    t_text.setLetterSpacing(0.8);
    t_text.setOutlineThickness(1);
    t_text.setOutlineColor(sf::Color::Black);
    t_text.setFillColor(sf::Color::White);
    t_visible = true;
    t_color = sf::Color::White;
    addComponent<Position>(position);
}

/************************************************************************
 * FUNCTION :       TextDisplay::initialize
 *
 * DESCRIPTION :
 *       Initializes the text display
 *
 *  INPUTS:  NONE
 *
 *  OUTPUTS: NONE
 *
 *  VERSION   	DATE    		WHO     DETAIL
 *  V1.00.00   	2021.03.10 	    JCB     Documentation Start
 *
 ************************************************************************/

void TextDisplay::initialize()
{
    t_text.setFont(*GlobalFont);
    t_text.setFillColor(t_color);
    t_text.setPosition(getComponent<Position>().getPosition());
}

/************************************************************************
 * FUNCTION :       TextDisplay::setText
 *
 * DESCRIPTION :
 *       Changes the displayed text
 *
 *  INPUTS:  string_t t   |  Text to be displayed
 *
 *  OUTPUTS: NONE
 *
 *  VERSION   	DATE    		WHO     DETAIL
 *  V1.00.00   	2021.03.10 	    JCB     Documentation Start
 *
 ************************************************************************/

void TextDisplay::setText(string_t t)
{
    if (t_bounds.getSize().x == 0 || t_bounds.getSize().y == 0)
    {
        t_text.setString(t);
        return;
    }

    uint16_t charPerLine = floor(t_bounds.getSize().y / (t_text.getCharacterSize() * t_text.getScale().y) * 6);
    uint16_t i = 1;

    for(;;)
    {
        if (i == t.length())
            break;

        if ((i % charPerLine) == 0)
        {
            auto c = t.at(i);
            if ((c != '.') && (c != ' '))
                t.insert(i, "-\n");
            else
                t.insert(i, "\n");

            if (t.at(i+1) == ' ') t.erase(i+1, 1);
        }
        i++;
    }

    t_text.setString(t);
}

/************************************************************************
 * FUNCTION :       TextDisplay::setPosition
 *
 * DESCRIPTION :
 *       Updates the text's position
 *
 *  INPUTS:  sf::Vector2f p  |  The new text position
 *
 *  OUTPUTS: NONE
 *
 *  VERSION   	DATE    		WHO     DETAIL
 *  V1.00.00   	2021.03.10 	    JCB     Documentation Start
 *
 ************************************************************************/

void TextDisplay::setPosition(sf::Vector2f p)
{
    getComponent<Position>().setPosition(p);
    t_text.setPosition(p);
}

/************************************************************************
 * FUNCTION :       TextDisplay::render
 *
 * DESCRIPTION :
 *       Render the text display
 *
 *  INPUTS:  sf::RenderWindow* window  | The window to render to
 *
 *  OUTPUTS: NONE
 *
 *  VERSION   	DATE    		WHO     DETAIL
 *  V1.00.00   	2021.03.10 	    JCB     Documentation Start
 *
 ************************************************************************/

void TextDisplay::render(sf::RenderWindow* window)
{
    if (t_visible)
        window->draw(t_text);
}