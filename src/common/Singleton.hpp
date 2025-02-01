#pragma once

namespace FW {
template <class T>
T& _()
{
    static T instance;
    return instance;
}
}
