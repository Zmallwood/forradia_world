// Copyright 2025 Andreas Åkerberg

#pragma once

namespace ForradiaWorld
{
    class SDLDevice
    {
      public:
        SDLDevice();

        void ClearCanvas() const;

        void PresentCanvas() const;

        auto GetWindow() const
        {
            return m_window;
        }
        auto GetRenderer() const
        {
            return m_renderer;
        }

      private:
        std::shared_ptr<SDL_Window> m_window;
        std::shared_ptr<SDL_Renderer> m_renderer;
    };
}
