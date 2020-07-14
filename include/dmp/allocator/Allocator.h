#pragma once

#include <stdlib.h>

#include "dmp/portability/Allocator.h"
#include "dmp/portability/Restrict.h"

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
void * dmpMalloc(const DmpAllocator * DMP_RESTRICT alloc, size_t byteSize);

/**
 * @brief invoke the callocFn of alloc, or the default allocator if null
 */
void * dmpCalloc(
    const DmpAllocator * DMP_RESTRICT alloc, size_t numElems, size_t byteSize);

/**
 * @brief invoke the reallocFn of alloc, or the default allocator if null
 */
void * dmpRealloc(
    const DmpAllocator * DMP_RESTRICT alloc, void * p, size_t newByteSize);

/**
 * @brief invoke the freeFn of alloc, or the default allocator if null
 */
void dmpFree(const DmpAllocator * DMP_RESTRICT alloc, void * p);

/**
 * @brief invoke the alignedAllocFn of alloc, or the default allocator if null
 */
void * dmpAlignedAlloc(
    const DmpAllocator * DMP_RESTRICT alloc, size_t alignment, size_t byteSize);

/**
 * @brief invoke the alignedFreeFn of alloc, or the default allocator if null
 */
void dmpAlignedFree(const DmpAllocator * DMP_RESTRICT alloc, void * p);
