#pragma once

#include <stdlib.h>

// void * DmpMallocFn(size_t byteSize)
typedef void * (*DmpMallocFn)(size_t);
// void * DmpCallocFn(size_t num, size_t byteSize)
typedef void * (*DmpCallocFn)(size_t, size_t);
// void * DmpReallocFn(void * toRealloc, size_t newByteSize)
typedef void * (*DmpReallocFn)(void *, size_t);
// void * DmpAlignedAllocFn(size_t alignment, size_t byteSize)
typedef void * (*DmpAlignedAllocFn)(size_t, size_t);
// void * DmpFreeFn(void * toFree)
typedef void (*DmpFreeFn)(void *);


typedef struct
{
  DmpMallocFn mallocFn;
  DmpCallocFn callocFn;
  DmpReallocFn reallocFn;
  DmpAlignedAllocFn alignedAllocFn;
  DmpFreeFn freeFn;
} DmpAllocator;

/**
 * @brief Return the default allocator
 * @return an allocator object populated by the stdlib allocators
 */
DmpAllocator getDefaultAllocator();

/**
 * @brief invoke the mallocFn of alloc, or the default allocator if null
 */
void * dmpMalloc(size_t byteSize,
                 const DmpAllocator * restrict alloc);

/**
 * @brief invoke the callocFn of alloc, or the default allocator if null
 */
void * dmpCalloc(size_t numElems,
                 size_t byteSize,
                 const DmpAllocator * restrict alloc);

/**
 * @brief invoke the reallocFn of alloc, or the default allocator if null
 */
void * dmpRealloc(void * p,
                  size_t newByteSize,
                  const DmpAllocator * restrict alloc);

/**
 * @brief invoke the alignedAllocFn of alloc, or the default allocator if null
 */
void * dmpAlignedAlloc(size_t alignment,
                       size_t byteSize,
                       const DmpAllocator * restrict alloc);

/**
 * @brief invoke the freeFn of alloc, or the default allocator if null
 */
void dmpFree(void * p,
             const DmpAllocator * restrict alloc);
