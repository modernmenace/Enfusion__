#include "Game.h"
#include <functional>

sf::Font*         GlobalFont;
sf::Vector2f      MousePosition;
ItemRegistry*     ItemRegistry::m_Instance = nullptr;
sf::View*         uiView = nullptr;


/*
 *  Game
 *
 *  DESC: Core game class, handles game loop and threading
 *
 *  NOTE: Multi-threading NEEDS to be implemented
 *
 */

Game::Game(int argc, char *argv[])
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
                                                          WINDOW_TITLE);
    srand(time(nullptr));
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(0);
    window.setActive(false);
    renderThread = new sf::Thread(std::bind(&Game::render, this, &window));
    GlobalFont = new sf::Font();
    GlobalFont->loadFromFile("Resources/Fonts/NotoMono-Regular.TTF");
    generateItemRegistry();
    generateControls();
    LevelManager::Instance()->setLevel("Level_1");
    Settings::Instance();
    SE_init(argv[0]);
    run(&window, renderThread);
}

/*
 *  Run
 *
 *  DESC: Run implements the core game loop
 *
 */

void Game::run(sf::RenderWindow* window, sf::Thread* renderThread) {
    sf::Clock timer;
    sf::Time tickRate;
    initialize();
    renderThread->launch();
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
    window->setVerticalSyncEnabled(true);
    window->setActive(true);
    while (window->isOpen())
    {
        if (flag_close)
        {
            window->close();
            renderThread->terminate();
        }
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
        if (event.type == sf::Event::Closed) flag_close = true;

        if (event.type == sf::Event::KeyPressed)
            LEVEL.handleInput(event.key.code);

        if (event.type == sf::Event::MouseButtonPressed)
            LEVEL.handleInput(event.mouseButton.button);
    }
}

