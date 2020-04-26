#include "Game.h"
#include <functional>

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
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
                                                          WINDOW_TITLE);
    srand(time(nullptr));
    window.setActive(false);
    static sf::Thread renderThread(std::bind(&Game::render, this, &window));
    renderThread.launch();
    GlobalFont = new sf::Font();
    GlobalFont->loadFromFile("Resources/Fonts/NotoMono-Regular.TTF");
    generateItemRegistry();
    LevelManager::Instance()->setLevel("Level_1");
    Settings::Instance();
    run(&window);
}

/*
 *  Run
 *
 *  DESC: Run implements the core game loop
 *
 */

void Game::run(sf::RenderWindow* window) {
    sf::Clock timer;
    sf::Time tickRate;
    initialize();

    while (window->isOpen()) {
        tickRate = timer.restart();
        processEvents(window);
        update(tickRate);
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

void Game::render(sf::RenderWindow* window)
{
    //TODO; multithreaded approach causes crash
    dbg_log(window)
    window->setActive(true);
    while (window->isOpen())
    {
        window->clear(sf::Color::Black);
        LEVEL.render(window);
        window->display();
    }
}

/*
 *  Process Events
 *
 *  DESC: Handles user input, window closing, and various other events
 *
 */

void Game::processEvents(sf::RenderWindow* window) {
    sf::Event event;
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window->close();

        if (event.type == sf::Event::KeyPressed)
            LEVEL.handleInput(event.key.code);

        if (event.type == sf::Event::MouseButtonPressed)
            LEVEL.handleInput(event.mouseButton.button);
    }
}

