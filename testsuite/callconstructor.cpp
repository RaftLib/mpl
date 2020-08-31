/**
 * dummy.cpp - 
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
#include "mpl.hpp"

template < class T > struct derived_dummy
{
    using tls_type = T;
};

int
main( )
{
   using qtype_t = mpl::fifo_queue< derived_dummy< int > /** just for base class **/ >;
   qtype_t q;

   return( EXIT_SUCCESS );
}
