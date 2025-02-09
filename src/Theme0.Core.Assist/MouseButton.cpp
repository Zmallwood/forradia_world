// Copyright 2025 Andreas Åkerberg

#include "MouseButton.hpp"

namespace ForradiaWorld
{
    void MouseButton::RegisterPress()
    {
        m_pressed = true;
        m_beenFired = true;
    }

    void MouseButton::RegisterRelease()
    {
        m_pressed = false;
        m_beenReleased = true;
    }

    bool MouseButton::GetBeenFiredPickResult()
    {
        auto result = m_beenFired;
        m_beenFired = false;
        return result;
    }

    bool MouseButton::GetBeenReleasedPickResult()
    {
        auto result = m_beenReleased;
        m_beenReleased = false;
        return result;
    }
}
