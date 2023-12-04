#include <Python.h>

/**
 * print_python_list_info - function that prints some basic
 * info about Python lists
 * @p: python list
 */
void print_python_list_info(PyObject *p)
{
    int elem;

    printf("[*] Size of the Python List = %lu\n", Py_SIZE(p));
    printf("[*] Allocated = %lu\n", ((PyListObject *)p)->allocated);

    for (elem = 0; elem < Py_SIZE(p); elem++)
        printf("Element %d: %s\n", elem, Py_TYPE(PyList_GetItem(p, elem))->tp_name);
}

static PyObject *wrap_print_python_list_info(PyObject *self, PyObject *args)
{
    PyObject *list;

    if (!PyArg_ParseTuple(args, "O", &list))
        return NULL;

    print_python_list_info(list);

    Py_RETURN_NONE;
}

static PyMethodDef module_methods[] = {
    {"print_python_list_info", wrap_print_python_list_info, METH_VARARGS,
     "Print information about a Python list."},
    {NULL, NULL, 0, NULL}};

static struct PyModuleDef module_def = {
    PyModuleDef_HEAD_INIT,
    "PyList",
    NULL,
    -1,
    module_methods};

PyMODINIT_FUNC PyInit_PyList(void)
{
    return PyModule_Create(&module_def);
}
