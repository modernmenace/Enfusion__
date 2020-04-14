#include "TextDisplay.h"

TextDisplay::TextDisplay(string_t text, sf::Vector2f position, uint16_t size)
{
    this->text.setString(text);
    this->text.setCharacterSize(size);
    addComponent<Position>(position);
}

void TextDisplay::initialize()
{
    text.setFont(*GlobalFont);
    text.setPosition(getComponent<Position>().getPosition());
}

void TextDisplay::setPosition(sf::Vector2f p)
{
    getComponent<Position>().setPosition(p);
    text.setPosition(getComponent<Position>().getPosition());
}

void TextDisplay::render(sf::RenderWindow* window)
{
    window->draw(text);
}