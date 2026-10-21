cmake_minimum_required(VERSION 3.20)

project(l3drAsm LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(lib/GLFW)

add_library(glad STATIC lib/glad/src/gl.c)

target_include_directories(glad PUBLIC
    lib/glad/include
)

add_executable(l3drAsm main.cpp)

set_target_properties(l3drAsm PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

target_include_directories(l3drAsm PRIVATE
    lib/glfw/deps
)

target_link_libraries(l3drAsm PRIVATE
    glfw
    glad
)
