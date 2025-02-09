#include "FileUtilities.hpp"

namespace ForradiaWorld
{
    std::string GetFileExtension(std::string_view path)
    {
        return path.substr(path.find_last_of('.') + 1).data();
    }

    std::string GetFileNameNoExtension(std::string_view path)
    {
        auto nameWithExtension = std::string(path.substr(path.find_last_of('/') + 1));

        return nameWithExtension.substr(0, nameWithExtension.find_last_of('.'));
    }
}
