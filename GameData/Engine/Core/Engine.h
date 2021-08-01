#ifndef ENFUSION_ENGINE_H
#define ENFUSION_ENGINE_H

#include <iostream>
#include <assert.h>
#include <memory>
#include <SFML/Graphics.hpp>
#include "AssetManager.h"
#include "CGlobal.h"

// Globals
extern sf::Font*                 GlobalFont;
extern sf::Vector2f              MousePosition;

// Item Useful Macros
#define forever for(;;)
typedef std::string string_t;

// resource paths
#define RESOURCE_PATH        "Resources/"

#define MISSING_TEXTURE      "MissingTexture.png"

// scale data
#define GLOBAL_SCALE_GAMEOBJECT sf::Vector2f(2.5f, 2.5f)
#define GLOBAL_SCALE_TILE       sf::Vector2f(2   , 2)

// debug macros
#if DEBUG_BUILD
    #define dbg_log(message) std::cout << message << std::endl;
    #define dbg_err(message) std::cout << "ERROR: " << message << std::endl;
#else
    #define dbg_log(message)
    #define dbg_err(message)
#endif

#define FRAMERATE_LIMIT 60

#endif //ENFUSION_ENGINE_H
