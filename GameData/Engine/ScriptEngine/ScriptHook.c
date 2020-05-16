#include <Python.h>
#include "ScriptHook.h"

/*
 *  ScriptHook
 *
 *  DESC: Handles extension of python interpreter and
 *        application specific functionality
 *
 */

//TODO: https://docs.python.org/3/extending/embedding.html
//TODO: see section 1.4

void SE_initializeHook(void)
{
    PyImport_AppendInittab("enfusion", &PyInit_enfusion);
}

static PyObject*
enf_return107(PyObject *self, PyObject *args)
{
    return PyLong_FromLong(107);
}

static PyMethodDef
EnfMethods[] = {
        {"return107", enf_return107, METH_VARARGS,
                "Return the number 107."},
        {NULL, NULL, 0, NULL}
};

static PyModuleDef
EnfModule = {
        PyModuleDef_HEAD_INIT, "enfusion", NULL, -1, EnfMethods,
        NULL, NULL, NULL, NULL
};

static PyObject*
PyInit_enfusion(void)
{
    return PyModule_Create(&EnfModule);
}