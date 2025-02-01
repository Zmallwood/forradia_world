#include "Game.hpp"
#include "engine/Engine.hpp"

namespace fw {
void Game::Run()
{
    std::cout << "run game\n";

    _<Engine>().Run();
}
}
