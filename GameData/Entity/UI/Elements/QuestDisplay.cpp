#include "QuestDisplay.h"
#include "../../../Engine/Component/Base/Sprite.h"


QuestDisplay::QuestDisplay() : q_title("Active Quests", sf::Vector2f(685, -225), 25)
{
    q_dropBox.addComponent<Position>(sf::Vector2f(875, -225));
    q_dropBox.addComponent<Sprite>("UI/ui.png");
}

void QuestDisplay::initialize()
{
    Entity::initialize();
    q_title.initialize();
    q_title.text().setFillColor(sf::Color::Yellow);
    q_dropBox.initialize();
    q_dropBox.getComponent<Sprite>().getSprite().setTextureRect(sf::IntRect(72, 64, 18, 16));
    q_dropBox.getComponent<Sprite>().getSprite().setScale(sf::Vector2f(2, 2));
}

void QuestDisplay::render(sf::RenderWindow* window)
{
    Entity::render(window);
    q_title.render(window);
    q_dropBox.render(window);
}