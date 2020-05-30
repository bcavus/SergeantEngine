# CMakeList.txt : CMake project for Sergeant3DEngine, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("Sergeant3DEngine")

# Include directories
include_directories($ENV{GLEW_DIR}/include)
include_directories($ENV{GLFW_DIR}/include)
include_directories($ENV{GLM_DIR}/glm)

# Linker directories
link_directories($ENV{GLEW_DIR}/lib/Release/x64)
link_directories($ENV{GLFW_DIR}/lib-vc2019)
link_directories($ENV{GLM_DIR}/glm)

# Package directories
find_package(OPENGL REQUIRED)

# Add local libraries
add_library(
    core
    Core/Window/window.h
    Core/Window/window.cpp
    Core/Shader/shader.h
    Core/Shader/shader.cpp
    Core/Vertex/vertex.h
    Core/Vertex/vertex.cpp
    Core/Mesh/mesh.h
    Core/Mesh/mesh.cpp
 )

 add_library(
     support
     Support/helper.h
     Support/helper.cpp
 )

# Add source to this project's executable.
add_executable(Sergeant3DEngine "Sergeant3DEngine.h" "Sergeant3DEngine.cpp" ${PROJECT_SOURCES})

# Link target executable and libraries to our application
target_link_libraries(Sergeant3DEngine ${OPENGL_LIBRARIES} glew32 glfw3dll)

# Link local target executable and libraries to our application
target_link_libraries(Sergeant3DEngine core support)


# TODO: Add tests and install targets if needed.
