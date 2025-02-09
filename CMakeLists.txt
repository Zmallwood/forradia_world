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

        src/Theme0.Core.Common.MathLibrary/RectF.hpp
        src/Theme0.Core.Common.MathLibrary/Size.hpp
        src/Theme0.Core.Common.MathLibrary/SizeF.hpp
        src/Theme0.Core.Common.MathLibrary/Point.hpp
        src/Theme0.Core.Common.MathLibrary/PointF.hpp

        src/Theme0.Core.Common/Singleton.hpp
        src/Theme0.Core.Common/Hash.hpp
        src/Theme0.Core.Common/SDLDeleter.hpp
        src/Theme0.Core.Common/FileUtilities.hpp
        src/Theme0.Core.Common/StringUtilities.hpp
        src/Theme0.Core.Common/CanvasUtilities.hpp
        src/Theme0.Core.Common/MouseUtilities.hpp
)
