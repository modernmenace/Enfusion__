#ifndef ENFUSION_LEVEL_H
#define ENFUSION_LEVEL_H

#include "../Core/Engine.h"

class Level {

public:
    Level();

    virtual void initialize();
    virtual void update();
    virtual void render();

private:
    std::string levelName;

};

#endif //ENFUSION_LEVEL_H
