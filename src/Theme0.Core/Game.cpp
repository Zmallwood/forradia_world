#include "Game.hpp"
#include "Theme0.Core.Devices/EngineDevice.hpp"

namespace FW {
void Game::Run()
{
    _<EngineDevice>().Run();
}
}
