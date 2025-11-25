#include "GC.h"

int GC_INIT(GC *gc) {}
int GC_CLEANUP(GC *gc) {}
int GC_DESTRUCT(GC *gc) {}

void *GC_ALLOCATE(GC *gc, size_t size) {}
void *GC_MALLOC(GC *gc, size_t size) {}
void GC_FREE(GC *gc, void *ptr) {}
