#ifndef ENFUSION___SETTINGS_H
#define ENFUSION___SETTINGS_H

#include "../Core/Engine.h"

#define CONTROL_NOT_FOUND UINT_MAX

class Settings {

public:
    Settings();
    static Settings* Instance();
    uint16_t control(string_t);

    inline void addControl(string_t name, uint16_t key)
    {
        controlMap.insert(std::make_pair(name, key));
    }

private:
    static Settings* m_Instance;

    std::map<string_t, uint16_t> controlMap;

};

#define CREATE_CONTROL(CONTROL_NAME, CONTROL_KEY) \
Settings::Instance()->addControl(CONTROL_NAME, CONTROL_KEY); \

#endif //ENFUSION___SETTINGS_H
