/**
 * @author: Jonathan Beard
 * @version: Thu Jun 18 08:08:03 2015
 * 
 * Copyright 2015 Jonathan Beard
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
#include <cstdint>
#include <iostream>
#include "signal.hpp"
#include "indexed_signal.hpp"


int
main( )
{
    /** 
     * test out three constructor types 
     */
    mpl::indexed_signal no_vars;
    
    mpl::indexed_signal both_vars( mpl::signal::quit, 5 );

    mpl::indexed_signal copy( both_vars );
    
    /**
     * test equality operators 
     */
    if( copy != both_vars )
    {
        return( EXIT_FAILURE );
    }
    if( copy == no_vars )
    {
        return( EXIT_FAILURE );
    }

    /**
     * test out print helpers 
     */
    std::cout << "copy: " << copy << "\n";
    std::cout << "both: " << both_vars << "\n";
    std::cout << "none: " << no_vars << "\n";
    return( EXIT_SUCCESS );
}
