#include "Engine.hpp"
#include "Core/SDLDevice/SDLDevice.hpp"
#include "Core/ScenesCore/SceneManager.hpp"
#include "PollEvents.hpp"

namespace FW {
void Engine::Run()
{
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
