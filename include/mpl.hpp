/**
 * mpl.hpp - 
 * @author: Jonathan Beard
 * @version: Mon Aug 31 07:31:18 2020
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
#ifndef MPL_HPP
#define MPL_HPP  1
#include <cstdint>
namespace mpl
{
/** 
 * mpl::fifo_queue - base class type, should be
 * specialized to make the specific queue that 
 * the user wants to implement. 
 */
template < class QTYPE > class fifo_queue
{
public:
    constexpr fifo_queue() = default;

    
    /**
     * get_tls_size - function returns the size of 
     * the data struct that the caller should allocate
     * and hand to the initialize_tls() function. 
     * @param - none
     * @return - std::size_t, size of data in bytes to 
     * allocate for call to initialize_tls
     */
    static constexpr std::size_t get_tls_size() noexcept
    {
        return( 0 );
    }

    
    /**
     * initialize_tls - initilize constexpr bits of the 
     * struct, caller can then set things like file descriptors
     * or whatever else needs to be set.
     */
    static void initialize_tls( typename QTYPE::tls_type &t )
    {
        return;
    }

    static void deinitialize_tls( typename QTYPE::tls_type &t )
    {
        return;
    }
};

} /** end namespace mpl **/
#endif /* END MPL_HPP */
