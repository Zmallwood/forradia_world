#include "World.hpp"
#include "WorldArea.hpp"

namespace ForradiaWorld
{
    World::World()
        : m_currentWorldArea(std::make_shared<WorldArea>())
    {
    }
}
