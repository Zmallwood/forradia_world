#include "Game.hpp"
#include "Engine/Engine.hpp"

namespace FW {
void Game::Run()
{
    _<Engine>().Run();
}
}
