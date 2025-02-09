// Copyright 2025 Andreas Åkerberg

#pragma once

namespace ForradiaWorld
{
    class Tile
    {
      public:
        auto GetGround() const
        {
            return m_ground;
        }

        void SetGround(std::string_view groundName)
        {
            m_ground = Hash(groundName);
        }

        auto GetObject() const
        {
            return m_object;
        }

        void SetObject(std::string_view objectName)
        {
            m_object = Hash(objectName);
        }

      private:
        int m_ground { 0 };
        int m_object { 0 };
    };
}
