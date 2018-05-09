#include <stdlib.h>

#include "allocator/Allocator.h"

#include "utility/Assert.h"

static const DmpAllocator defaultAllocatorObj =
  {
    malloc,
    calloc,
    realloc,
    aligned_alloc,
    free
  };

DmpAllocator getDefaultAllocator()
{
  return defaultAllocatorObj;
}

void * dmpMalloc(size_t byteSize,
                 const DmpAllocator * restrict alloc)
{
  if (alloc)
    {
      dmpExpect("Non-null allocator has mallocFn set", alloc->mallocFn);
      return alloc->mallocFn(byteSize);
    }

  dmpExpect("Default allocator has mallocFn set", defaultAllocatorObj.mallocFn);

  return defaultAllocatorObj.mallocFn(byteSize);
}

void * dmpCalloc(size_t numElems,
                 size_t byteSize,
                 const DmpAllocator * restrict alloc)
{
  if (alloc)
    {
      dmpExpect("Non-null allocator has callocFn set", alloc->callocFn);
      return alloc->callocFn(numElems, byteSize);
    }

  dmpExpect("Default allocator has callocFn set", defaultAllocatorObj.callocFn);

  return defaultAllocatorObj.callocFn(numElems, byteSize);
}

void * dmpRealloc(void * p,
                  size_t newByteSize,
                  const DmpAllocator * restrict alloc)
{
  if (alloc)
    {
      dmpExpect("Non-null allocator has reallocFn set", alloc->reallocFn);
      return alloc->reallocFn(p, newByteSize);
    }

  dmpExpect("Default allocator has reallocFn set", defaultAllocatorObj.reallocFn);

  return defaultAllocatorObj.reallocFn(p, newByteSize);
}

void * dmpAlignedAlloc(size_t alignment,
                       size_t byteSize,
                       const DmpAllocator * restrict alloc)
{
  if (alloc)
    {
      dmpExpect("Non-null allocator has alignedAllocFn set", alloc->alignedAllocFn);
      return alloc->alignedAllocFn(alignment, byteSize);
    }

  dmpExpect("Default allocator has alignedAllocFn set", defaultAllocatorObj.alignedAllocFn);

  return defaultAllocatorObj.alignedAllocFn(alignment, byteSize);
}

void dmpFree(void * p,
             const DmpAllocator * restrict alloc)
{
  if (alloc)
    {
      dmpExpect("Non-null allocator has freeFn set", alloc->freeFn);
      alloc->freeFn(p);
      return;
    }

  dmpExpect("Default allocator has freeFn set", defaultAllocatorObj.freeFn);

  defaultAllocatorObj.mallocFn(p);
}
