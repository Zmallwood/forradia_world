#pragma once

namespace fw {
template <class T>
T& _()
{
    static T instance;
    return instance;
}
}
