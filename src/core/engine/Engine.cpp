#include "Engine.hpp"
#include "PollEvents.hpp"
#include "core/scenes_core/SceneManager.hpp"
#include "core/sdl_device/SDLDevice.hpp"

namespace FW {
void Engine::Run()
{
    std::cout << "engine run\n";
    srand(time(nullptr));

    while (m_running) {
        PollEvents();
        _<SceneManager>().UpdateCurrentScene();
        _<SDLDevice>().ClearCanvas();
        _<SceneManager>().RenderCurrentScene();
        _<SDLDevice>().PresentCanvas();
    }
}
}
