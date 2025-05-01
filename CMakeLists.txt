cmake_minimum_required(VERSION 3.31.4)
project(MODEL-VIEWER)

# Set the output directory for executables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Include dependencies
include_directories(${CMAKE_SOURCE_DIR}/dependencies/include ${CMAKE_SOURCE_DIR}/headers)
link_directories(${CMAKE_SOURCE_DIR}/dependencies/lib)

# Collect all source files
file(GLOB_RECURSE SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp ${CMAKE_SOURCE_DIR}/src/*.c)

# Create the executable
add_executable(main WIN32 ${SOURCES})

# Link libraries
target_link_libraries(main glfw3)

add_custom_target(copy_resources
    COMMAND ${CMAKE_COMMAND} -E rm -rf "${CMAKE_BINARY_DIR}/bin/shaders"
    COMMAND ${CMAKE_COMMAND} -E rm -rf "${CMAKE_BINARY_DIR}/bin/textures"
    COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_SOURCE_DIR}/shaders" "${CMAKE_BINARY_DIR}/bin/shaders"
    COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_SOURCE_DIR}/textures" "${CMAKE_BINARY_DIR}/bin/textures"
    COMMENT "Copying shaders and textures into bin/..."
)

# Make sure main depends on copy_resources
add_dependencies(main copy_resources)