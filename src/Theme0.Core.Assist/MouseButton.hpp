// Copyright 2025 Andreas Åkerberg

#pragma once

namespace ForradiaWorld
{
    class MouseButton
    {
      public:
        void RegisterPress();
        void RegisterRelease();
        bool GetBeenFiredPickResult();
        bool GetBeenReleasedPickResult();

        auto GetPressed() const
        {
            return m_pressed;
        }

      private:
        bool m_pressed { false };
        bool m_beenFired { false };
        bool m_beenReleased { false };
    };
}
