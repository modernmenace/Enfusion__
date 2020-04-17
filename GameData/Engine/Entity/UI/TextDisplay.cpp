#include <cmath>
#include "TextDisplay.h"

TextDisplay::TextDisplay(string_t text, sf::Vector2f position, uint16_t size, sf::RectangleShape bounds)
{
    t_bounds = bounds;
    t_text.setString(text);
    t_text.setCharacterSize(size);
    t_text.setLetterSpacing(0.8);
    addComponent<Position>(position);
}

void TextDisplay::initialize()
{
    t_text.setFont(*GlobalFont);
    t_text.setPosition(getComponent<Position>().getPosition());
}

void TextDisplay::setText(string_t t)
{
    if (t_bounds.getSize().x == 0 || t_bounds.getSize().y == 0)
    {
        t_text.setString(t);
        return;
    }

    uint16_t charPerLine = floor(t_bounds.getSize().y / (t_text.getCharacterSize() * t_text.getScale().y) * 6); //TODO: formula
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

void TextDisplay::setPosition(sf::Vector2f p)
{
    getComponent<Position>().setPosition(p);
    t_text.setPosition(getComponent<Position>().getPosition());
}

void TextDisplay::render(sf::RenderWindow* window)
{
    window->draw(t_text);
}