cmake_minimum_required(VERSION 3.7)
project(untitled1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_PREFIX_PATH /home/jafar/Qt5.7.0/5.7/gcc_64/)

find_package(Qt5 REQUIRED COMPONENTS Core Widgets Gui Network)

set(SOURCE_FILES main.cpp header/Server.h source/Server.cpp)
add_executable(untitled1 ${SOURCE_FILES})

target_link_libraries(untitled1 Qt5::Core Qt5::Widgets Qt5::Gui Qt5::Network)