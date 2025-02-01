cmake_minimum_required (VERSION 3.5)
project (forradia_world LANGUAGES CXX)
set (CMAKE_CXX_STANDARD 20)

IF (WIN32)
    set(CMAKE_CXX_FLAGS "-static-libstdc++ -static-libgcc -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,-Bdynamic,--no-whole-archive")
ENDIF()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)
add_compile_definitions(SDL_MAIN_HANDLED)
#add_compile_definitions(GLM_ENABLE_EXPERIMENTAL)
add_executable(forradia_world ${SRC_FILES})

IF (WIN32)
    target_link_libraries(forradia_world
        SDL2
        SDL2_image
        SDL2_ttf
        #opengl32
        #glu32
        #glew32
    )
ELSE()
    target_link_libraries(forradia_world
        SDL2
        SDL2_image
        SDL2_ttf
        #GL
        #GLU
        #GLEW
    )
ENDIF()

target_include_directories(forradia_world PUBLIC "src")

target_precompile_headers(forradia_world
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

#        src/Common/MathLibrary/RectangleF.hpp
#        src/Common/MathLibrary/Size.hpp
#        src/Common/MathLibrary/SizeF.hpp
#        src/Common/MathLibrary/Point.hpp
#        src/Common/MathLibrary/PointF.hpp
#
        src/common/Singleton.hpp
        src/common/Hash.hpp
        src/common/SDLDeleter.hpp
#        src/Common/FileUtilities.hpp
#        src/Common/StringUtilities.hpp
#        src/Common/CanvasUtilities.hpp
#        src/Common/MouseUtilities.hpp
)
