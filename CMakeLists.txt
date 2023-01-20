cmake_minimum_required(VERSION 3.24)
project(game)

set(CMAKE_CXX_STANDARD 17)

add_executable(game src/main.cpp src/debug/gl_error.cpp lib/game/include/DEBUG/gl_error.h src/CameraSystem.cpp lib/game/include/GAME/CameraSystem.h src/debug/glfw_error.cpp lib/game/include/DEBUG/glfw_error.h src/GameManager.cpp lib/game/include/GAME/GameManager.h src/RenderSystem.cpp lib/game/include/GAME/RenderSystem.h src/VertexBuffer.cpp lib/game/include/GAME/VertexBuffer.h src/ShaderLoader.cpp lib/game/include/GAME/ShaderLoader.h src/ShaderInterface.cpp lib/game/include/GAME/ShaderInterface.h lib/game/include/GAME/Vector3.h lib/game/include/GAME/VertexData.h src/ResourceManager.cpp lib/game/include/GAME/ResourceManager.h lib/game/include/GAME/TetrahedronVertices.h lib/game/include/GAME/CubeVertices.h src/helpers/Vector4.cpp lib/game/include/GAME/Vector4.h src/helpers/Vector3.cpp src/helpers/Matrix3.cpp lib/game/include/GAME/Matrix3.h src/ShaderData.cpp lib/game/include/GAME/ShaderData.h src/Entity.cpp lib/game/include/GAME/Entity.h src/MovementSystem.cpp lib/game/include/GAME/MovementSystem.h src/PlayerInputSystem.cpp lib/game/include/GAME/PlayerInputSystem.h src/helpers/Vector2.cpp lib/game/include/GAME/Vector2.h src/Scene.cpp lib/game/include/GAME/Scene.h)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

find_package(OpenGL REQUIRED)

add_subdirectory(lib/glfw-3.3.8)

target_link_libraries(game OpenGL::GL)
target_link_libraries(game glfw)

include_directories(lib/game/include)
include_directories(lib/glfw-3.3.8/include)