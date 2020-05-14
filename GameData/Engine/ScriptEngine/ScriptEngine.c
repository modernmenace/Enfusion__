#include <Python/Python.h>

void SE_init(const char* programName)
{
    //initialize engine here
    //Py_Initialize();
    //PyRun_SimpleString("from time import time,ctime\n"
    //                   "print('Today is', ctime(time()))\n");
    printf(programName);
}