#include "Settings.h"

Settings* Settings::m_Instance = nullptr;

Settings* Settings::Instance()
{
    if (m_Instance == nullptr)
        m_Instance = new Settings();

    return m_Instance;
}

uint16_t Settings::control(uint16_t control)
{
    //TODO: implement this
}