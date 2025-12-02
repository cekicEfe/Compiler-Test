# Set the minimum version of CMake that can be used
# To find the cmake version run
# $ cmake --version
cmake_minimum_required(VERSION 3.30)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set the project name
project (TEST_LISP_MAIN)
set (CMAKE_CXX_STANDARD 11)

# Create a sources variable with a link to all cpp files to compile
set(SOURCES
    src/main.cpp
    src/Parser/Parser.tab.hh
    src/Parser/Parser.tab.cc

    src/Lexer/Lexer.h
    src/Lexer/lex.yy.cc
)

# Add an executable with the above sources
add_executable(TEST_LISP_MAIN ${SOURCES})

target_link_libraries(TEST_LISP_MAIN
    gccjit
    gc
    )

target_include_directories(TEST_LISP_MAIN
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/src/Parser
        ${PROJECT_SOURCE_DIR}/src/Lexer
)
