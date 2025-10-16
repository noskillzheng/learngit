cmake_minimum_required(VERSION 3.10)

project(oop_try2)

add_executable(${PROJECT_NAME}
    src/main.cpp)

include_directories(include)    

add_library(TOOLS_STATIC STATIC src/vehicle.cpp)
target_link_libraries(${PROJECT_NAME}  TOOLS_STATIC)
 
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
#cmake -B build -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
