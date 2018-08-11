#ifndef ENFUSION_ENGINE_H
#define ENFUSION_ENGINE_H

#include <iostream>
#include "AssetManager.h"

// If true, debug messages are enabled
#define DEBUG_BUILD true

#define WINDOW_TITLE __TIME__

#define WINDOW_WIDTH  1920
#define WINDOW_HEIGHT 1080

#define RESOURCE_PATH        "Resources/"
#define RESOURCE_PATH_OBJECT "Objects/"

//Useful macros
#if DEBUG_BUILD
    #define dbg_log(message) std::cout << message << std::endl;
    #define dbg_err(message) std::cout << "ERROR: " << message << std::endl;
#else
    #define dbg_log(message)
    #define dbg_err(message)
#endif

#endif //ENFUSION_ENGINE_H
