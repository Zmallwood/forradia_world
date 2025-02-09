#include "StringUtilities.hpp"

namespace ForradiaWorld
{
    std::string Replace(std::string_view text, char replaced, char replacedWith)
    {
        std::string textData = text.data();
        std::replace(textData.begin(), textData.end(), replaced, replacedWith);

        return textData;
    }
}
