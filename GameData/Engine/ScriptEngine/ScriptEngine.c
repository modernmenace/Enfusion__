#include "python3.8/Python.h"
#include "ScriptEngine.h"
#include <unistd.h>

bool SE_init(const char* programName)
{
    //initialize engine here
    if (!SE_checkForScripts()) return false;

    printf("Script Engine Initializing (Python ");
    printf(PY_VERSION);
    printf(")");

    Py_SetProgramName(programName);
    Py_Initialize();

    Py_Finalize();

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
        strncpy (dirNames[i],de->d_name, strlen(de->d_name));
        i++;
    }

    int j = 0;
    for(j = 0; j < dirCount; j++)
    {
        printf(dirNames[j]);
        printf("\n");
    }

    closedir(dr);

    //TODO: check each mod directory to see if mod.py is present


    return true;


}