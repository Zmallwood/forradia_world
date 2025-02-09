cmake_minimum_required (VERSION 3.5)
project (ForradiaWorldLANGUAGES CXX)
set (CMAKE_CXX_STANDARD 20)

IF (WIN32)
    set(CMAKE_CXX_FLAGS "-static-libstdc++ -static-libgcc -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,-Bdynamic,--no-whole-archive")
ENDIF()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)
add_compile_definitions(SDL_MAIN_HANDLED)
#add_compile_definitions(GLM_ENABLE_EXPERIMENTAL)
add_executable(ForradiaWorld ${SRC_FILES})

IF (WIN32)
  target_link_libraries(ForradiaWorld
        SDL2
        SDL2_image
        SDL2_ttf
        #opengl32
        #glu32
        #glew32
    )
ELSE()
  target_link_libraries(ForradiaWorld
        SDL2
        SDL2_image
        SDL2_ttf
        #GL
        #GLU
        #GLEW
    )
ENDIF()

target_include_directories(ForradiaWorld PUBLIC "src")

target_precompile_headers(ForradiaWorld
    PRIVATE
        <iostream>
        <map>
        <memory>
        <filesystem>
        <algorithm>
        <set>
        <vector>
        <functional>

        <SDL2/SDL.h>
        <SDL2/SDL_image.h>
        <SDL2/SDL_ttf.h>

        src/Theme1.Core.Common/Enums.hpp
        src/Theme1.Core.Common/MathLib.hpp
        src/Theme1.Core.Common/Utils.hpp
)
