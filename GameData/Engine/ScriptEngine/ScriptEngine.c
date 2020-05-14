#include "python3.8/Python.h"

void SE_init(const char* programName)
{
    //initialize engine here
    printf("Script Engine Initializing (Python ");
    printf(PY_VERSION);
    printf(")");
    Py_SetProgramName(programName);
}