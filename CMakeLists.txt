# Set the minimum version of CMake that can be used
# To find the cmake version run
# $ cmake --version
cmake_minimum_required(VERSION 3.30)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set the project name
project (TEST_LISP_MAIN)
set (CMAKE_CXX_STANDARD 17) # To use variants etc

# Create a sources variable with a link to all cpp files to compile
set(SOURCES
    src/main.cpp

    src/Frontend/Parser/Parser.hpp
    src/Frontend/Parser/Parser.cpp

    src/Frontend/Lexer/Scanner.hpp
    src/Frontend/Lexer/Scanner.cpp
)

# Add an executable with the above sources
add_executable(TEST_LISP_MAIN ${SOURCES})

target_link_libraries(TEST_LISP_MAIN
    gccjit
    gc
    )

target_include_directories(TEST_LISP_MAIN
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/src/Frontend/Parser
        ${PROJECT_SOURCE_DIR}/src/Frontend/Lexer

        ${PROJECT_SOURCE_DIR}/src/Backend/Interpreter
        ${PROJECT_SOURCE_DIR}/src/Backend/SymbolTable
        ${PROJECT_SOURCE_DIR}/src/Backend/Data
)
