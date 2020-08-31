/**
 * signal.hpp - 
 * @author: Jonathan Beard
 * @version: Sun May 11 08:26:13 2014
 * 
 * Copyright 2014 Jonathan Beard
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
#ifndef RAFTSIGNALVARS_HPP
#define RAFTSIGNALVARS_HPP  1
#include <cstdint>
#include <limits>

namespace mpl{
/** 
 * far more signals than we'll probably need (32-bits that is), but
 * I figure why not reserve the space now.  < 0xffff = system signals,
 * the rest are user space.
 */
using signal_type = std::uint8_t;

static constexpr signal_type max_system_signal( 
    std::numeric_limits< mpl::signal_type >::max() 
);

enum signal : signal_type {
   none = 0,
   quit,
   term,
   eof = max_system_signal
};

static const char* signal_strings[]
= { "none", "quit", "term", "eof" };

}
#endif /* END RAFTSIGNALVARS_HPP */
