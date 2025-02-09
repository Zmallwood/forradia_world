// Copyright 2025 Andreas Åkerberg

#include "MouseButton.hpp"

namespace ForradiaWorld
{

    void MouseButton::RegisterPress()
    {
        /*\
Set states corresponding to a mouse button press.
*/
        m_pressed = true;

        m_beenFired = true;
    }

    void MouseButton::RegisterRelease()
    {
        /*\
Set states corresponding to a mouse button release.
*/
        m_pressed = false;

        m_beenReleased = true;
    }

    bool MouseButton::GetBeenFiredPickResult()
    {
        /*\
Get state, reset it and return.
*/
        auto result = m_beenFired;

        m_beenFired = false;

        return result;
    }

    bool MouseButton::GetBeenReleasedPickResult()
    {
        /*\
Get state, reset it and return.
*/
        auto result = m_beenReleased;

        m_beenReleased = false;

        return result;
    }

}
