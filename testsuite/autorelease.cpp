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
#include "autorelease.tcc"


/**
 * create a dummy proxy 
 * of the fifo in case 
 * we want to do some testing
 * on the functionality here
 * as well.
 */
struct dummy_fifo
{
    void send( const mpl::signal &s )
    {
        (void)(s);
        return;
    }

    void unpeek() noexcept
    {
        return;
    }

    void recycle() noexcept
    {
        return;
    }

    template < class T > T& peek( mpl::signal * const sig )
    {
        (void)(sig);
        return( (*reinterpret_cast< T*>( &temp )) );
    }

    std::uintptr_t temp = 0;
};

int
main( )
{
    int x = 0;
    dummy_fifo df;
    mpl::signal s = mpl::none;
    
    /**
     * basic pop constructor
     */
    mpl::autorelease< int, dummy_fifo, mpl::autotype::poptype > poptype( x, s, df );
    /** 
     * copy constructor
     */
    auto poptype_copy( poptype );
    
    std::cout << poptype_copy << "\n";
    std::cout << poptype << "\n";


    /**
     * alloc type constructor
     */
    mpl::autorelease< int, dummy_fifo, mpl::autotype::allocatetype > alloctype( x, df );
   
    /** test copy **/
    auto alloc_copy( alloctype );
    
    std::cout << alloc_copy << "\n";
    (*alloc_copy) = 10;
    std::cout << alloc_copy << "\n";


    return( EXIT_SUCCESS );
}
