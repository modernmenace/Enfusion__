#ifndef ENFUSION___SCRIPTENGINE_H
#define ENFUSION___SCRIPTENGINE_H

#include <stdbool.h>
#include <dirent.h>

typedef struct
{
    uint16_t       id;
    char*          name;
    char*          directory;
} SE_Mod;

bool SE_init(const char*);
bool SE_checkForScripts(void);

#endif //ENFUSION___SCRIPTENGINE_H
