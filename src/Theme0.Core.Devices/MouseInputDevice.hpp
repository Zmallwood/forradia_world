#pragma once

namespace ForradiaWorld
{
    class MouseButton;

    class MouseInputDevice
    {
      public:
        MouseInputDevice();

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
