#ifndef ENFUSION___SCRIPTENGINE_H
#define ENFUSION___SCRIPTENGINE_H

#include <stdbool.h>

typedef struct
{
    uint16_t       id;
    char           name[1024];
    char           directory[1024];
} SE_Mod;

typedef struct
{
    SE_Mod* mods;
    size_t  used;
    size_t  size;
} SE_ModList;

extern SE_ModList SE_mods;

bool SE_init(const char*);
bool SE_checkForScripts(void);
void SE_initScripts(void);
void SE_listScripts(void);

#endif //ENFUSION___SCRIPTENGINE_H
