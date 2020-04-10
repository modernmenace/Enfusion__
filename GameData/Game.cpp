#include "Game.h"

std::unique_ptr<sf::Font> GlobalFont;

/*
 *  Game
 *
 *  DESC: Core game class, handles game loop and threading
 *
 *  NOTE: Multi-threading NEEDS to be implemented
 *
 */

Game::Game() : mWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE)
{
    GlobalFont = std::make_unique<sf::Font>();
    GlobalFont->loadFromFile("Resources/Fonts/TYPEWR.TTF");
    generateItemRegistry();
    LevelManager::Instance()->setLevel("Level_1");
    run();
}

/*
 *  Run
 *
 *  DESC: Run implements the core game loop
 *
 */

void Game::run() {
    sf::Clock timer;
    sf::Time tickRate;
    initialize();

    while (mWindow.isOpen()) {
        tickRate = timer.restart();
        processEvents();
        update(tickRate);
        render();
    }
}

/*
 *  Initialize
 *
 *  DESC: One-time initialization, called before game loop
 *
 */

void Game::initialize()
{
    LEVEL.initialize();
}

/*
 *  Update
 *
 *  DESC: This function is used to perform the updating of gameobjects,
 *        levels, and various other game features
 *
 */

void Game::update(sf::Time tickRate)
{
    LEVEL.update(tickRate);
}

/*
 *  Render
 *
 *  DESC: Handles drawing/rendering on the window
 *
 */

void Game::render()
{
    mWindow.clear(sf::Color::Black);
    LEVEL.render(&mWindow);
    mWindow.display();
}

/*
 *  Process Events
 *
 *  DESC: Handles user input, window closing, and various other events
 *
 */

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

