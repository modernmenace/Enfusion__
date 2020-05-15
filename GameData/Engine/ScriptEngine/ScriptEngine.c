#ifdef _WIN32
#include "Python.h"
#endif
#ifdef __APPLE__
#include "python3.8/Python.h"
#endif
#include "ScriptEngine.h"
#include <unistd.h>

#define dbg_log(m) \
printf(m);         \
printf("\n");      \

SE_ModList SE_mods;

bool SE_init(const char* programName)
{
    //initialize engine here
    if (!SE_checkForScripts()) return false;

    printf("Script Engine Initializing (Python ");
    printf(PY_VERSION);
    printf(")\n");
    int i;
    for(i = 0; i < SE_mods.used; i++)
    {
        printf("%u", (unsigned int)SE_mods.mods[i].id);
        printf(": ");
        printf(SE_mods.mods[i].name);
        printf(" (");
        printf(SE_mods.mods[i].directory);
        printf(")\n");
    }

    wchar_t *program = Py_DecodeLocale(programName, NULL);
    Py_SetProgramName(program);
    Py_Initialize();

    //TODO: Python stuff here

    Py_Finalize();
    PyMem_RawFree(program);

    return true;
}

bool SE_checkForScripts(void)
{
    struct dirent *de;
    char dir[PATH_MAX];
    getcwd(dir, sizeof(dir));
    strncat(dir, "/Mods", 5);
    DIR *dr = opendir(dir);

    if (dr == NULL)
    {
        return false; // mod directory doesnt exist
    }

    uint16_t dirCount = 0;
    while ((de = readdir(dr)) != NULL)
    {
        if (strcmp(".", de->d_name) == 0 || strcmp("..", de->d_name) == 0 || strcmp(".DS_Store", de->d_name) == 0)
            continue;
        dirCount++;
    }
    rewinddir(dr);

    char* dirNames[dirCount];
    uint16_t i = 0;
    while ((de = readdir(dr)) != NULL)
    {
        if (strcmp(".", de->d_name) == 0 || strcmp("..", de->d_name) == 0 || strcmp(".DS_Store", de->d_name) == 0)
            continue;

        dirNames[i] = (char*) malloc (strlen(de->d_name)+1);
        strncpy (dirNames[i],de->d_name, strlen(de->d_name)+1);
        i++;
    }
    closedir(dr);

    SE_mods.mods = (SE_Mod *)malloc(10 * sizeof(SE_Mod));
    SE_mods.used = 0;
    SE_mods.size = 10;

    int j = 0;
    for(j = 0; j < dirCount; j++)
    {
        getcwd(dir, sizeof(dir));
        strncat(dir, "\\Mods\\", 6);
        strncat(dir, dirNames[j], strlen(dirNames[j]));
        dr = opendir(dir);

        bool validDir = false;
        while ((de = readdir(dr)) != NULL)
        {
            if (strcmp(".", de->d_name) == 0 || strcmp("..", de->d_name) == 0 || strcmp(".DS_Store", de->d_name) == 0)
                continue;
            if (strcmp(de->d_name, "mod.py") == 0)
            {
                validDir = true;
                break;
            }

        }

        if (validDir == true)
        {
            SE_Mod element;
            if (SE_mods.used == 0)
                element.id = 0;
            else
                element.id   = SE_mods.mods[SE_mods.used].id + 1;

            strcpy(element.name, "Placeholder");
            strcpy(element.directory, dir);

            if (SE_mods.used == SE_mods.size)
            {
                SE_mods.size *= 2;
                SE_mods.mods = (SE_Mod *)realloc(SE_mods.mods, SE_mods.size * sizeof(SE_Mod));
            }
            SE_mods.mods[SE_mods.used++] = element;
        }

        closedir(dr);
    }

    if (SE_mods.used > 0) return true;
    else                  return false;
}