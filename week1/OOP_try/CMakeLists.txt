cmake_minimum_required(VERSION 3.10)

project(OOP_vehicle)

add_executable(${PROJECT_NAME}
    src/main.cpp)

include_directories(include)    

#add_library(TOOLS_STATIC STATIC src/specific_adapter.cpp specific_system.cpp)
#target_link_libraries(${PROJECT_NAME}  TOOLS_STATIC)
 
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)