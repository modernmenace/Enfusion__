#ifndef ENFUSION_ENGINE_H
#define ENFUSION_ENGINE_H

#include <iostream>
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

#define WINDOW_TITLE __TIME__

#define WINDOW_WIDTH  1920
#define WINDOW_HEIGHT 1080

// resource paths
#define RESOURCE_PATH        "Resources/"
#define RESOURCE_PATH_OBJECT "Objects/"
#define RESOURCE_PATH_AI     "AI/"

#define MISSING_TEXTURE      "MissingTexture.png"

// scale data
#define GLOBAL_SCALE_GAMEOBJECT sf::Vector2f(2.5f, 2.5f)

// debug macros
#if DEBUG_BUILD
    #define dbg_log(message) std::cout << message << std::endl;
    #define dbg_err(message) std::cout << "ERROR: " << message << std::endl;
#else
    #define dbg_log(message)
    #define dbg_err(message)
#endif

// other useful macros
#define FLIP_SPRITE(Sprite_Name) Sprite_Name.scale(-1.f,1.f);

#endif //ENFUSION_ENGINE_H
