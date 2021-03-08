cmake_minimum_required(VERSION 2.8)

## Use the variable PROJECT_NAME for changing the target name
set( PROJECT_NAME "ImpPlayer" )
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./bin)
SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11 -pthread")

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -g")
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_BUILD_TYPE RelWithDebInfo)

## Set our project name
project(${PROJECT_NAME})

#Bring the headers, such as Student.h into the project
include_directories("include" "include/Render" "include/Utils")

include_directories("lib/")
include_directories("lib/tinyxml2")


## Use all the *.cpp files we found under this folder for the project
FILE(GLOB SRCS "src/*.cpp" "src/Render/*.cpp"  "src/Utils/*.cpp" "lib/tinyxml2/tinyxml2.cpp")

## Define the executable
add_executable(${PROJECT_NAME} ${SRCS})

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})


#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions

find_package (Threads)
find_package(SFML 2 REQUIRED network audio graphics window system)
find_package (Python3 COMPONENTS Interpreter Development REQUIRED)
find_package(PythonLibs REQUIRED)

include_directories(${PYTHON_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES} ${PYTHON_LIBRARIES})
