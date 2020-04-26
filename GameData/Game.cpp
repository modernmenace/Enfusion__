#include "Game.h"

sf::RenderWindow* WINDOW;
sf::Font*         GlobalFont;
sf::Vector2f      MousePosition;
ItemRegistry* ItemRegistry::m_Instance = nullptr;
sf::View* uiView = nullptr;


/*
 *  Game
 *
 *  DESC: Core game class, handles game loop and threading
 *
 *  NOTE: Multi-threading NEEDS to be implemented
 *
 */

Game::Game()
{
    WINDOW     = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
                                                          WINDOW_TITLE);
    srand(time(nullptr));
    GlobalFont = new sf::Font();
    GlobalFont->loadFromFile("Resources/Fonts/NotoMono-Regular.TTF");
    generateItemRegistry();
    LevelManager::Instance()->setLevel("Level_1");
    Settings::Instance();
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

    while (WINDOW->isOpen()) {
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
    WINDOW->clear(sf::Color::Black);
    LEVEL.render(WINDOW);
    WINDOW->display();
}

/*
 *  Process Events
 *
 *  DESC: Handles user input, window closing, and various other events
 *
 */

void Game::processEvents() {
    sf::Event event;
    while (WINDOW->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            WINDOW->close();

        if (event.type == sf::Event::KeyPressed)
            LEVEL.handleInput(event.key.code);

        if (event.type == sf::Event::MouseButtonPressed)
            LEVEL.handleInput(event.mouseButton.button);
    }
}

