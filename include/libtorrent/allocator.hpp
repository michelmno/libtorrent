/*

Copyright (c) 2009-2016, Arvid Norberg
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:

    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in
      the documentation and/or other materials provided with the distribution.
    * Neither the name of the author nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE.

*/

#ifndef TORRENT_ALLOCATOR_HPP_INCLUDED
#define TORRENT_ALLOCATOR_HPP_INCLUDED

#include "libtorrent/config.hpp"

#include <cstddef>
#include <cstdint>

namespace libtorrent
{
	TORRENT_EXTRA_EXPORT int page_size();

	// these allocation functions are meant to be used for large memory
	// allocations (large means at least megabytes). The memory area that's
	// allocated is page aligned. This is primarily meant for allocating the disk
	// cache, which also means the allocation may be marked no to be included in
	// coredumps etc.
	TORRENT_EXTRA_EXPORT char* page_allocate(std::int64_t bytes);
	TORRENT_EXTRA_EXPORT void page_free(char* block, std::int64_t size);

	// indicate we won't be needing the content in this region. Allow the kernel
	// to recycle the physical memory behind it.
	TORRENT_EXTRA_EXPORT void page_dont_need(char* block, std::int64_t size);
}

#endif

