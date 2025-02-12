/*
 * Copyright (c) 2025 Andreas Åkerberg.
 * All rights reserved.
 *
 * This file is part of Forradia World.
 *
 * Licensed under the MIT License (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     https://opensource.org/licenses/MIT
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "ObjectIndexDevice.hpp"

namespace ForradiaWorld
{
    ObjectIndexDevice::ObjectIndexDevice()
    {
        using namespace ObjectFlags;

        // Adding various object entries to the index with specific flags
        AddEntry("ObjectWoodenFenceHorizontal", "Wooden fence", OBJECT_ALLOWS_SIGHT);
        AddEntry("ObjectWoodenFenceVertical", "Wooden fence", OBJECT_ALLOWS_SIGHT);
        AddEntry("ObjectWoodenFenceNW", "Wooden fence", OBJECT_ALLOWS_SIGHT);
        AddEntry("ObjectWoodenFenceNE", "Wooden fence", OBJECT_ALLOWS_SIGHT);
        AddEntry("ObjectWoodenFenceSE", "Wooden fence", OBJECT_ALLOWS_SIGHT);
        AddEntry("ObjectWoodenFenceSW", "Wooden fence", OBJECT_ALLOWS_SIGHT);
        AddEntry("ObjectPinkFlower", "Pink flower", OBJECT_ALLOWS_SIGHT);
    }

    bool ObjectIndexDevice::ObjectAllowsSight(int objectHash) const
    {
        // Check if the object hash exists in the entries
        if (m_entries.contains(objectHash))
        {
            // Retrieve the flags associated with the object
            auto flags = m_entries.at(objectHash).flags;

            // Check if the 'OBJECT_ALLOWS_SIGHT' flag is set
            return (flags & ObjectFlags::OBJECT_ALLOWS_SIGHT) != 0;
        }

        // Return false if the object hash is not found
        return false;
    }

    void ObjectIndexDevice::AddEntry(std::string_view objectName, std::string_view label, int flags)
    {
        // Insert a new entry in the object index with the specified hash, label, and flags
        m_entries.insert({ Hash(objectName), { label.data(), flags } });
    }
}
