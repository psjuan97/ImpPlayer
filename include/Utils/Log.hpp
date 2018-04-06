#pragma once

#include <spdlog/spdlog.h>
#include <string>


namespace spd = spdlog;

namespace impvm
{

    

class Log
{
public:
    static std::shared_ptr<spd::logger> console;
public:
    static void info(std::string text);    
    static void warn(std::string text);
    static void error(std::string text);
    static void init(std::string text);
};

}

