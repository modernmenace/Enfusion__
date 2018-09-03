#include "Game.h"

/*
 *  Game
 *
 *  DESC: Core game class, handles game loop and threading
 *
 *  NOTE: Multi-threading NEEDS to be implemented
 *
 */

Game::Game() : mWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE), levelManager("Level_1")
{
    run();
}

/*
 *  Run
 *
 *  DESC: Run implements the core game loop
 *
 */

void Game::run() {
    initialize();

    while (mWindow.isOpen()) {
        processEvents();
        update();
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

void Game::update()
{
    LEVEL.update();
}

/*
 *  Render
 *
 *  DESC: Handles drawing/rendering on the window
 *
 */

void Game::render()
{
    mWindow.clear(sf::Color::Green);
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

