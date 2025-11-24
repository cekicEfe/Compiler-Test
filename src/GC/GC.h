#ifndef MY_GARBAGE_COLLECTOR_H
#define MY_GARBAGE_COLLECTOR_H

#include <cstddef>
#include <cstdlib>

#define MAX_HEAP_SIZE 256

struct GC_OBJECT {
  const void *mHeldObject;
  int mMarked;
} typedef GC_OBJECT;

struct GC_HEAP {
  GC_OBJECT mObjects[MAX_HEAP_SIZE];
  size_t mRootCount;
} typedef GC_HEAP;

struct GC {
  GC_HEAP mpHeap;
} typedef GC;

int GC_INIT();
int GC_CLEANUP();
int GC_EXIT();

void *GC_ALLOCATE(size_t size);
void *GC_MALLOC(size_t size);
void GC_FREE(void *ptr);

#endif
