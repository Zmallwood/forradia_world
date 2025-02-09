// Copyright 2025 Andreas Åkerberg

#pragma once

namespace ForradiaWorld
{
    template <class T>
    T& _()
    {
        static T instance;
        return instance;
    }
}
