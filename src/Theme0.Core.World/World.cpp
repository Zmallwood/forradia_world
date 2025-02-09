#include "World.hpp"
#include "WorldArea.hpp"

namespace FW {
World::World()
    : m_currentWorldArea(std::make_shared<WorldArea>())
{
}
}
