#ifndef ENFUSION___SETTINGS_H
#define ENFUSION___SETTINGS_H

#include "../Core/Engine.h"

#define CONTROLS_INVENTORY_MENU 1
#define CONTROLS_PAUSE_MENU     2
#define CONTROLS_SPRINT         3

class Settings {

public:
    static Settings* Instance();
    static uint16_t control(uint16_t);

private:

    static Settings* m_Instance;


};


#endif //ENFUSION___SETTINGS_H
