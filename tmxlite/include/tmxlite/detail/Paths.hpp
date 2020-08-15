/*********************************************************************
Matt Marchant 2020
http://trederia.blogspot.com

tmxlite - Zlib license.

This software is provided 'as-is', without any express or
implied warranty. In no event will the authors be held
liable for any damages arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute
it freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented;
you must not claim that you wrote the original software.
If you use this software in a product, an acknowledgment
in the product documentation would be appreciated but
is not required.

2. Altered source versions must be plainly marked as such,
and must not be misrepresented as being the original software.

3. This notice may not be removed or altered from any
source distribution.
*********************************************************************/

#ifndef PATHS_INC_HPP_
#define PATHS_INC_HPP_

#include <string>
#include <sstream>

#include <cstdlib>

namespace tmx
{
    static std::string getFilePath(const std::string& path)
    {
        //TODO this doesn't actually check that there is a file at the
        //end of the path, or that it's even a valid path...

        static auto searchFunc = [](const char separator, const std::string& path)->std::string
        {
            std::size_t i = path.rfind(separator, path.length());
            if (i != std::string::npos)
            {
                return(path.substr(0, i + 1));
            }

            return "";
        };


#ifdef _WIN32 //try windows formatted paths first
        std::string retVal = searchFunc('\\', path);
        if (!retVal.empty()) return retVal;
#endif

        return searchFunc('/', path);
    }
}

#endif // ANDROID_INC_HPP_
