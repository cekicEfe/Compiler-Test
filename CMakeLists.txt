# Set the minimum version of CMake that can be used
# To find the cmake version run
# $ cmake --version
cmake_minimum_required(VERSION 3.30)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set the project name
project (TEST_LISP_MAIN)

# Create a sources variable with a link to all cpp files to compile
set(SOURCES
    src/main.c
    src/Parser/Parser.tab.h

    src/Parser/Parser.tab.c
    src/Lexer/lex.yy.c
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
