#include "TextDisplay.h"

TextDisplay::TextDisplay(std::string text, sf::Vector2f position, uint16_t size)
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

void TextDisplay::render(sf::RenderWindow* window)
{
    window->draw(text);
}

void TextDisplay::setText(std::string text)
{
    this->text.setString(text);
}