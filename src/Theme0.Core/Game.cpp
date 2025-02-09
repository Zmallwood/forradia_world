#include "Game.hpp"
#include "Theme0.Core.Devices/EngineDevice.hpp"

namespace ForradiaWorld
{
    void Game::Run()
    {
        _<EngineDevice>().Run();
    }
}
