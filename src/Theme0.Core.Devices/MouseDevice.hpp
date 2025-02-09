// Copyright 2025 Andreas Åkerberg

#pragma once

namespace ForradiaWorld
{

    class MouseButton;

    class MouseDevice
    {
      public:
        MouseDevice();

        void RegisterButtonPress(Uint8 button);

        void RegisterButtonRelease(Uint8 button);

        auto GetLeftButton() const
        {
            return m_leftButton;
        }
        auto GetRightButton() const
        {
            return m_leftButton;
        }

      private:
        std::shared_ptr<MouseButton> m_leftButton;
        std::shared_ptr<MouseButton> m_rightButton;
    };

}
