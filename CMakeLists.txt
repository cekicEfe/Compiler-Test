# Set the minimum version of CMake that can be used
# To find the cmake version run
# $ cmake --version
cmake_minimum_required(VERSION 3.30)

# Set the project name
project (HALE_LISP_MAIN)

# Create a sources variable with a link to all cpp files to compile
set(SOURCES
    src/main.cpp
)

# Add an executable with the above sources
add_executable(HALE_LISP_MAIN ${SOURCES})

target_link_libraries(HALE_LISP_MAIN
    gccjit
    )

# Set the directories that should be included in the build command for this target
# when running g++ these will be included as -I/directory/path/
# target_include_directories(HALE_LISP_MAIN
#     PRIVATE 
#         ${PROJECT_SOURCE_DIR}/include
# )
