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

int GC_INIT(GC *gc);
int GC_CLEANUP(GC *gc);
int GC_DESTRUCT(GC *gc);

void *GC_ALLOCATE(GC *gc, size_t size);
void *GC_MALLOC(GC *gc, size_t size);
void GC_FREE(GC *gc, void *ptr);

#endif
