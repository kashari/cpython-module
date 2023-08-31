#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <string.h>
#include <ctype.h>

static PyObject *trim(PyObject *self, PyObject *args) {
    const char *input;

    if (!PyArg_ParseTuple(args, "s", &input)) {
        return NULL;
    }

    size_t input_length = strlen(input);
    char *output = (char *)malloc(input_length + 1);  // +1 for null terminator
    if (output == NULL) {
        PyErr_NoMemory();
        return NULL;
    }

    int j = 0;
    for (size_t i = 0; i < input_length; i++) {
        if (!isspace((unsigned char)input[i])) {
            output[j++] = input[i];
        }
    }
    output[j] = '\0';

    PyObject *result = Py_BuildValue("s", output);
    free(output);
    return result;
}

static PyMethodDef stringutilmodule_methods[] = {
    {"trim", trim, METH_VARARGS, "Trim string algorithm"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef stringutilmodule = {
    PyModuleDef_HEAD_INIT,
    "stringutil",
    NULL,
    -1,
    stringutilmodule_methods
};

PyMODINIT_FUNC PyInit_stringutil(void) {
    return PyModule_Create(&stringutilmodule);
}
