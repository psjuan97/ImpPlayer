#include <EntityLoader.hpp>


std::string EntityLoader::getEntityRoute(std::string file){
    PyObject *pName, *pModule, *pFunc, *pValue, *pArgs;
    Py_Initialize();
    PyRun_SimpleString("import sys\n"
                        "sys.path.insert(0, './pyModules')\n"
                        "print(sys.path)");    
    pName = PyUnicode_DecodeFSDefault("entityLoader");
    pModule = PyImport_Import(pName);

    pFunc = PyObject_GetAttrString(pModule, "getClassEntity");
    Py_XDECREF(pFunc);
    
    pArgs = PyTuple_New(1);
    PyTuple_SetItem(pArgs, 0, PyUnicode_DecodeFSDefault(file.c_str()));
    pValue = PyObject_CallObject(pFunc, pArgs);
    Py_FinalizeEx();
    return PyUnicode_AsUTF8(pValue);
}
