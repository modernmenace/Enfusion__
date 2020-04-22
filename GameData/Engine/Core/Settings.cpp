#include "Settings.h"

Settings* Settings::m_Instance = nullptr;

Settings* Settings::Instance()
{
    if (m_Instance == nullptr)
        m_Instance = new Settings();

    return m_Instance;
}

Settings::Settings()
{
    //load settings file here (documents?)
    dbg_log("Settings Initializing")
    //get directory different for platforms

#ifdef __WIN32
    //find directory windows
    int bytes = GetModuleFileName(NULL, pBuf, len);
#endif
#ifdef __APPLE__
    //find directory mac

#endif


}

uint16_t Settings::control(uint16_t control)
{
    //TODO: implement this
}