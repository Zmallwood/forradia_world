#include "StringUtilities.hpp"

namespace FW {
std::string Replace(std::string_view text, char replaced, char replacedWith)
{
    std::string textData = text.data();
    std::replace(textData.begin(), textData.end(), replaced, replacedWith);

    return textData;
}

float ConvertWidthToHeight(float width)
{
    return width * GetAspectRatio();
}

float ConvertHeightToWidth(float height)
{
    return height / GetAspectRatio();
}
}
