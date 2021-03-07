
#define PY_SSIZE_T_CLEAN
#include <python3.9/Python.h>

#include <string>

class EntityLoader{

public:
    EntityLoader(){};
    std::string getEntityRoute(std::string entityName);
};