#define PY_SSIZE_T_CLEAN
#include <python3.7/Python.h>
#include "wrapper.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* wrapper(int seed, int level)
{
    char level_1[5][64] = {"Assembly is so cool!", "reverseEngineer", "diveIntoSystems", "crackMe", "USMAEECS"};




    PyObject *pName, *pModule, *pFunc;
    PyObject *pArgs, *pValue;
    int i;


    Py_Initialize();

    // I had to add the following two lines to make it work
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append(\".\")");

    pName = PyUnicode_DecodeFSDefault("rand");
    /* Error checking of pName left out */

    pModule = PyImport_Import(pName);
    Py_DECREF(pName);

    if (pModule != NULL) {
        pFunc = PyObject_GetAttrString(pModule, "grab");
        /* pFunc is a new reference */

        if (pFunc && PyCallable_Check(pFunc)) {
            pArgs = PyTuple_New(6);
            //PyTuple_SetItem(pArgs, 0, PyUnicode_FromString(argv[1]));
            PyTuple_SetItem(pArgs, 0, PyLong_FromLong(seed));
            for (i = 0; i < 5; ++i) {
                pValue = PyUnicode_FromString(level_1[i]);
                if (!pValue) {
                    Py_DECREF(pArgs);
                    Py_DECREF(pModule);
                    fprintf(stderr, "Cannot convert argument\n");
                    return "42";
                }
                /* pValue reference stolen here: */
                PyTuple_SetItem(pArgs, i+1, pValue);
            }
            pValue = PyObject_CallObject(pFunc, pArgs);
            Py_DECREF(pArgs);
            if (pValue != NULL) {
                //printf("Result of call: %ld\n", PyLong_AsLong(pValue));
                return PyUnicode_AsUTF8(pValue);
                Py_DECREF(pValue);
            }
            else {
                Py_DECREF(pFunc);
                Py_DECREF(pModule);
                PyErr_Print();
                fprintf(stderr,"Call failed\n");
                return "59";
            }
        }
        else {
            if (PyErr_Occurred())
                PyErr_Print();
            //fprintf(stderr, "Cannot find function \"%s\"\n", argv[2]);
        }
        Py_XDECREF(pFunc);
        Py_DECREF(pModule);
    }
    else {
        PyErr_Print();
        //fprintf(stderr, "Failed to load \"%s\"\n", argv[1]);
        return "73";
    }
    if (Py_FinalizeEx() < 0) {
        return "76";
    }
    return "78";
}
