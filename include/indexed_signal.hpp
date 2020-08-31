/**
 * signal.hpp - 
 * @author: jonathan beard
 * @version: wed dec 31 15:14:56 2014
 * 
 * copyright 2014 jonathan beard
 * 
 * licensed under the apache license, version 2.0 (the "license");
 * you may not use this file except in compliance with the license.
 * you may obtain a copy of the license at:
 *
 *   http://www.apache.org/licenses/license-2.0
 *
 * unless required by applicable law or agreed to in writing, software
 * distributed under the license is distributed on an "as is" basis,
 * without warranties or conditions of any kind, either express or implied.
 * see the license for the specific language governing permissions and
 * limitations under the license.
 */
#ifndef mplindexedsignal_hpp
#define mplindexedsignal_hpp  1

#include <cstddef>
#include "signal.hpp"

namespace mpl
{

struct indexed_signal
{
    using index_t = std::size_t;

    /**
     * default constructor, doesn't do much.
     */
    constexpr indexed_signal() = default;

    /**
     * constructor with set index as param
     */
    constexpr indexed_signal( const mpl::signal s, 
                              const index_t     n ) : sig( s ),
                                                      index( n ){}
    /** 
     * copy constructor, just copies signal
     * by value, and index. 
     */
    constexpr indexed_signal( const indexed_signal &other ) : sig( other.sig ),
                                                              index( other.index )
    {} 

    /**
     * return just the signal itself, no indexing
     * @return mpl::signal
     */
    constexpr operator const mpl::signal& () noexcept 
    {
        return( sig );
    }

    /**
     * getindex - return the position of this signal with
     * respect to the current array 
     */
    constexpr index_t getindex() noexcept
    {
        return( index );
    }
    
    /**
     * various equality operators. 
     */
    constexpr bool operator ==( const indexed_signal &other )
    {
        return( other.sig == sig && other.index == index );
    }

    constexpr bool operator !=( const indexed_signal &other )
    {
        return( other.sig != sig || other.index != index );
    }
    
    constexpr bool operator ==( const indexed_signal &&other )
    {
        return( other.sig == sig && other.index == index );
    }

    constexpr bool operator !=( const indexed_signal &&other )
    {
        return( other.sig != sig || other.index != index );
    }


    friend std::ostream& operator << (std::ostream &os, const indexed_signal &s )
    {
        os << s.index << " - " << mpl::signal_strings[ s.sig ];
        return( os );
    }

#pragma pack( push, 1 )
    const mpl::signal   sig     =   mpl::none;
    const index_t       index   =   0;
#pragma pack( pop )    
};

} /** end namespace mpl **/
#endif /* end mplindexedsignal_hpp */
