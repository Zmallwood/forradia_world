// Copyright 2025 Andreas Åkerberg

#include "HeroDevice.hpp"

namespace ForradiaWorld
{

    void HeroDevice::MoveUp()
    {
        m_position.y--;
    }

    void HeroDevice::MoveRight()
    {
        m_position.x++;
    }

    void HeroDevice::MoveLeft()
    {
        m_position.x--;
    }

    void HeroDevice::MoveDown()
    {
        m_position.y++;
    }

}
