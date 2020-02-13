#ifndef ENFUSION_ENGINE_H
#define ENFUSION_ENGINE_H

#include <iostream>
#include <assert.h>
#include <memory>
#include <SFML/Graphics.hpp>
#include "AssetManager.h"

/*
 *  Engine
 *
 *  DESC: Core engine header, stores key definitions used
 *        throughout the engine
 *
 */

// if true, debug messages are enabled
#define DEBUG_BUILD true

#define WINDOW_TITLE "Enfusion++"

#define WINDOW_WIDTH  1920
#define WINDOW_HEIGHT 1080

#define MAX_COMPONENTS 6


// Globals
extern std::unique_ptr<sf::Font> GlobalFont;

// Misc Useful Macros
#define forever for(;;)
typedef std::string string_t;

// resource paths
#define RESOURCE_PATH        "Resources/"
#define RESOURCE_PATH_OBJECT "Objects/"
#define RESOURCE_PATH_AI     "AI/"

#define MISSING_TEXTURE      "MissingTexture.png"

// scale data
#define GLOBAL_SCALE_GAMEOBJECT sf::Vector2f(2.5f, 2.5f)
#define GLOBAL_SCALE_TILE       sf::Vector2f(2.5f, 2.5f)

// debug macros
#if DEBUG_BUILD
    #define dbg_log(message) std::cout << message << std::endl;
    #define dbg_err(message) std::cout << "ERROR: " << message << std::endl;
#else
    #define dbg_log(message)
    #define dbg_err(message)
#endif

#endif //ENFUSION_ENGINE_H
