#include "Game.h"

Game::Game() : mWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE), levelManager("Level_1")
{
    run();
}

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
    levelManager.getCurrentLevel().initialize();
}

void Game::update()
{
    levelManager.getCurrentLevel().update();
}

void Game::render()
{
    mWindow.clear(sf::Color::Cyan);
    levelManager.getCurrentLevel().render(&mWindow);
    mWindow.display();
}

void Game::processEvents() {
    sf::Event event;
    while (mWindow.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            mWindow.close();

        if (event.type == sf::Event::KeyPressed)
            levelManager.getCurrentLevel().handleInput(event.key.code);
    }
}

