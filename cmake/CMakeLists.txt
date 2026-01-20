cmake_minimum_required(VERSION 3.10)

project(TodoLib)
set(CMAKE_CXX_STANDARD 17)

add_library(todo STATIC 
    ../src/task_manager.cpp 
    ../src/task.cpp 
    ../src/ui/task_render.cpp
)

target_include_directories(todo PUBLIC ../include)

add_executable(example ../example.cpp)

target_link_libraries(example PRIVATE todo)