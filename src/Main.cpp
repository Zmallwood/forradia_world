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

#include "Theme1/Theme1.hpp"

int main(int argc, char** argv)
{
    // Use the ForradiaWorld namespace to access relevant classes and functions.
    using namespace ForradiaWorld;

    // Run the Theme1 theme.
    _<Theme1>().Run();

    // Return 0 to indicate successful execution of the program.
    return 0;
}
