#include <stdlib.h>

#include "dmp/core/allocator/Allocator.h"
#include "dmp/core/utility/Assert.h"

static void * systemMalloc(size_t byteSize, void * userData)
{
   return malloc(byteSize);
}

static void * systemCalloc(size_t num, size_t byteSize, void * userData)
{
   return calloc(num, byteSize);
}

static void * systemRealloc(
    void * toRealloc, size_t newByteSize, void * userData)
{
   return realloc(toRealloc, newByteSize);
}

static void systemFree(void * toFree, void * userData)
{
   free(toFree);
}

static void * systemAlignedAlloc(
    size_t alignment, size_t byteSize, void * userData)
{
   return aligned_alloc(alignment, byteSize);
}

static void systemAlignedFree(void * toFree, void * userData)
{
   aligned_free(toFree);
}

static const DmpAllocator defaultAllocatorObj = { .mallocFn = systemMalloc,
   .callocFn = systemCalloc,
   .reallocFn = systemRealloc,
   .freeFn = systemFree,
   .alignedAllocFn = systemAlignedAlloc,
   .alignedFreeFn = systemAlignedFree,
   .userData = NULL };

DmpAllocator getDefaultAllocator()
{
   return defaultAllocatorObj;
}

void * dmpMalloc(const DmpAllocator * DMP_RESTRICT alloc, size_t byteSize)
{
   if (alloc)
   {
      dmpExpect("Non-null allocator has mallocFn set", alloc->mallocFn);
      return alloc->mallocFn(byteSize, alloc->userData);
   }

   dmpExpect(
       "Default allocator has mallocFn set", defaultAllocatorObj.mallocFn);

   return defaultAllocatorObj.mallocFn(byteSize, defaultAllocatorObj.userData);
}

void * dmpCalloc(
    const DmpAllocator * DMP_RESTRICT alloc, size_t numElems, size_t byteSize)
{
   if (alloc)
   {
      dmpExpect("Non-null allocator has callocFn set", alloc->callocFn);
      return alloc->callocFn(numElems, byteSize, alloc->userData);
   }

   dmpExpect(
       "Default allocator has callocFn set", defaultAllocatorObj.callocFn);

   return defaultAllocatorObj.callocFn(
       numElems, byteSize, defaultAllocatorObj.userData);
}

void * dmpRealloc(
    const DmpAllocator * DMP_RESTRICT alloc, void * p, size_t newByteSize)
{
   if (alloc)
   {
      dmpExpect("Non-null allocator has reallocFn set", alloc->reallocFn);
      return alloc->reallocFn(p, newByteSize, alloc->userData);
   }

   dmpExpect(
       "Default allocator has reallocFn set", defaultAllocatorObj.reallocFn);

   return defaultAllocatorObj.reallocFn(
       p, newByteSize, defaultAllocatorObj.userData);
}

void dmpFree(const DmpAllocator * DMP_RESTRICT alloc, void * p)
{
   if (alloc)
   {
      dmpExpect("Non-null allocator has freeFn set", alloc->freeFn);
      alloc->freeFn(p, alloc->userData);
      return;
   }

   dmpExpect("Default allocator has freeFn set", defaultAllocatorObj.freeFn);

   defaultAllocatorObj.freeFn(p, defaultAllocatorObj.userData);
}

void * dmpAlignedAlloc(
    const DmpAllocator * DMP_RESTRICT alloc, size_t alignment, size_t byteSize)
{
   if (alloc)
   {
      dmpExpect(
          "Non-null allocator has alignedAllocFn set", alloc->alignedAllocFn);
      return alloc->alignedAllocFn(alignment, byteSize, alloc->userData);
   }

   dmpExpect("Default allocator has alignedAllocFn set",
       defaultAllocatorObj.alignedAllocFn);

   return defaultAllocatorObj.alignedAllocFn(
       alignment, byteSize, defaultAllocatorObj.userData);
}

void dmpAlignedFree(const DmpAllocator * DMP_RESTRICT alloc, void * p)
{
   if (alloc)
   {
      dmpExpect(
          "Non-null allocator has alignedFreeFn set", alloc->alignedFreeFn);
      alloc->alignedFreeFn(p, alloc->userData);
      return;
   }

   dmpExpect("Default allocator has alignedFreeFn set",
       defaultAllocatorObj.alignedFreeFn);

   defaultAllocatorObj.alignedFreeFn(p, defaultAllocatorObj.userData);
}
