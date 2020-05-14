#include "python3.8/Python.h"
#include "ScriptEngine.h"

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
    //TODO: Implement this
    //TODO: check mod directory
    return true;
}