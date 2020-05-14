#include "python3.8/Python.h"
#include "ScriptEngine.h"
#include <dirent.h>
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
        //TODO: mod directory does not exist
        printf("Could not open current directory" );
        return 0;
    }

    while ((de = readdir(dr)) != NULL)
        printf("%s\n", de->d_name);

    closedir(dr);

    return true;


}