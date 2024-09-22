cmake_minimum_required(VERSION 3.10)

project(freedom)

# Add the submodule as a dependency
add_subdirectory(libfreedom)

# Create the executable
add_executable(freedom src/main.c)

# Link the submodule library to the main project as a shared library
target_link_libraries(freedom INTERFACE libfreedom)

target_include_directories(freedom PUBLIC libfreedom/include)
