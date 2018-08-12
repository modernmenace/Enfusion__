#include "Game.h"

Game::Game() : mWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE), levelManager("Level_1")
{
    run();
}

// Need to come back and multi-thread this
void Game::run() {
    initialize();
    while (mWindow.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Game::initialize()
{
    LEVEL.initialize();
}

void Game::update()
{
    LEVEL.update();
}

void Game::render()
{
    mWindow.clear(sf::Color::Cyan);
    LEVEL.render(&mWindow);
    mWindow.display();
}

void Game::processEvents() {
    sf::Event event;
    while (mWindow.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            mWindow.close();

        if (event.type == sf::Event::KeyPressed)
            LEVEL.handleInput(event.key.code);
    }
}

