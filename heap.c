#include <stdio.h>

int main(void) {
  int t[10];
  heapType heap;

  init(&heap);
  for (int i = 0; i<10; i++) {
    t[i] = rand();
    insertMaxHeap(&heap, t[i]);
  }
}
