// Copyright 2025 Andreas Åkerberg

#pragma once

namespace ForradiaWorld
{

    /*\
Base class which all other scene classes inherit from.
*/
    class IScene
    {
      public:
        void Update();

        void Render() const;

      protected:
        virtual void UpdateDerived() { }

        virtual void RenderDerived() const { }
    };

}
