cmake_minimum_required(VERSION 3.10)

project(Freedom)

# Add the submodule as a dependency
add_subdirectory(libfreedom)

# Create the executable
add_executable(Freedom src/main.c)

# Link the submodule library to the main project as a shared library
target_link_libraries(Freedom INTERFACE libfreedom)

target_include_directories(Freedom PUBLIC libfreedom/include)
