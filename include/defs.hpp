/**
 * defs.hpp - 
 * @author: Jonathan Beard
 * @version: Sat 22 August 2020
 * 
 * Copyright 2020 Jonathan Beard
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at:
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef MPLDEFS_HPP
#define MPLDEFS_HPP  1
#include <cstdint>

namespace mpl
{
    
    /**
     * have a stable version of a byte. 
     */
    using byte_t                            = std::uint8_t;
    /**
     * _unused - pretty much zero cost way to get rid of 
     * unused warning in a way that is "c++ compliant". 
     * @param x - T&&
     */
    template < class T > constexpr static void _unused( T &&x )
    { 
        (void)(x); 
    }
}


#endif /* END MPLDEFS_HPP */
