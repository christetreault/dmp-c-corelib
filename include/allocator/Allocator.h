#pragma once

#include <stdlib.h>

#include "Portability/Allocator.h"
#include "Portability/Restrict.h"

// void * DmpMallocFn(size_t byteSize, void * userData)
typedef void * (*DmpMallocFn)(size_t, void *);
// void * DmpCallocFn(size_t num, size_t byteSize, void * userData)
typedef void * (*DmpCallocFn)(size_t, size_t, void *);
// void * DmpReallocFn(void * toRealloc, size_t newByteSize, void * userData)
typedef void * (*DmpReallocFn)(void *, size_t, void *);
// void DmpFreeFn(void * toFree, void * userData)
typedef void (*DmpFreeFn)(void *, void *);
// void * DmpAlignedAllocFn(size_t alignment, size_t byteSize, void * userData)
typedef void * (*DmpAlignedAllocFn)(size_t, size_t, void *);
// void DmpAlignedFreeFn(void * toFree, void * userData)
typedef void (*DmpAlignedFreeFn)(void *, void *);

typedef struct
{
   DmpMallocFn mallocFn;
   DmpCallocFn callocFn;
   DmpReallocFn reallocFn;
   DmpFreeFn freeFn;
   DmpAlignedAllocFn alignedAllocFn;
   DmpAlignedFreeFn alignedFreeFn;

   void * userData;
} DmpAllocator;

/**
 * @brief Return the default allocator
 * @return an allocator object populated by the stdlib allocators
 */
DmpAllocator getDefaultAllocator();

/**
 * @brief invoke the mallocFn of alloc, or the default allocator if null
 */
void * dmpMalloc(size_t byteSize, const DmpAllocator * DMP_RESTRICT alloc);

/**
 * @brief invoke the callocFn of alloc, or the default allocator if null
 */
void * dmpCalloc(size_t numElems, size_t byteSize, const DmpAllocator * DMP_RESTRICT alloc);

/**
 * @brief invoke the reallocFn of alloc, or the default allocator if null
 */
void * dmpRealloc(void * p, size_t newByteSize, const DmpAllocator * DMP_RESTRICT alloc);

/**
 * @brief invoke the freeFn of alloc, or the default allocator if null
 */
void dmpFree(void * p, const DmpAllocator * DMP_RESTRICT alloc);

/**
 * @brief invoke the alignedAllocFn of alloc, or the default allocator if null
 */
void * dmpAlignedAlloc(size_t alignment, size_t byteSize, const DmpAllocator * DMP_RESTRICT alloc);

/**
 * @brief invoke the alignedFreeFn of alloc, or the default allocator if null
 */
void dmpAlignedFree(void * p, const DmpAllocator * DMP_RESTRICT alloc);