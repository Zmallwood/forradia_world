#include "PlayerDevice.hpp"

namespace ForradiaWorld
{
    void PlayerDevice::MoveUp()
    {
        m_position.y--;
    }

    void PlayerDevice::MoveRight()
    {
        m_position.x++;
    }

    void PlayerDevice::MoveLeft()
    {
        m_position.x--;
    }

    void PlayerDevice::MoveDown()
    {
        m_position.y++;
    }
}
