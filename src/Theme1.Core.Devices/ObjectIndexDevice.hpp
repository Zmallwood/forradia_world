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

#pragma once

namespace ForradiaWorld
{
    namespace ObjectFlags
    {
        /**
        * Flag indicating that the object allows sight (player can see above it)
        */
        inline constexpr int OBJECT_ALLOWS_SIGHT = 1 << 0;

        /**
        * Flag indicating that the object is an obstacle (cannot be passed through)
        */
        inline constexpr int OBJECT_OBSTACLE = 1 << 1;

        /**
        * Flag indicating that the object is unmovable (cannot be interacted with in terms of movement)
        */
        inline constexpr int OBJECT_UNMOVABLE = 1 << 2;
    }

    /**
    * Structure representing an entry in the object index, including its label and flags
    */
    struct ObjectIndexEntry
    {
        /**
        * The label or name of the object
        */
        std::string label;

        /**
        * The flags that describe properties of the object (e.g., visibility, obstacle)
        */
        int flags { 0 };
    };

    /**
    * Class responsible for managing and querying object entries, indexed by object hashes
    */
    class ObjectIndexDevice
    {
      public:
        /**
        * Constructor that initializes the object index with predefined entries
        */
        ObjectIndexDevice();

        /**
        * Checks whether an object with the specified hash allows sight (player can look above it)
        *
        * @param objectHash The hash of the object to check
        * @return True if the object allows sight, false otherwise
        */
        bool ObjectAllowsSight(int objectHash) const;

      private:
        /**
        * Adds a new object entry to the index with the given name, label, and flags
        *
        * @param objectName The name of the object (used to generate a hash)
        * @param label A descriptive label for the object
        * @param flags Flags that describe properties of the object
        */
        void AddEntry(std::string_view objectName, std::string_view label, int flags);

        /**
        * A map that stores object entries indexed by their hash values
        */
        std::map<int, ObjectIndexEntry> m_entries;
    };

}
