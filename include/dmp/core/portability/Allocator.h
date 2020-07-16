#pragma once

#ifdef _MSC_VER

#include <malloc.h>

#ifndef aligned_alloc
#define aligned_alloc _aligned_malloc
#define aligned_free _aligned_free
#else
#error "TODO: MSVC has aligned_alloc now?"
#endif

#else

#include <stdlib.h>
// MS free implementation is incompatable with the C standard requirement that
// free support pointers returned by aligned_alloc. To support code sharing
// with windows, we'll just force non windows platforms to pretend that
// aligned_free is a thing
#define aligned_free free

#endif