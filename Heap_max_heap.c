#include <stdio.h>
#define MAX_ELEMENT 200
typedef struct {
  int key;
} element;
typedef struct {
  element heap[MAX_ELEMENT];
  int heap_size;
} HeapType;

void init(HeapType *h) {
  h->heap_size = 0;
}

void insert_max_heap(HeapType *h, element item) {
  int i;
  i = ++(h->heap_size);

  while((i != 1) && (item.key > h->heap[i/2].key)) {
   h->heap[i] = h->heap[i/2];
   i /= 2;
  }
  h->heap[i] = item;
}

element delete_max_heap(HeapType *h) {
  int parent, child;
  element item, temp;
  item = h->heap[1];
  temp = h->heap[(h->heap_size)--];
  parent = 1;
  child = 2;
  while (child <= h->heap_size) {
    if((child < h->heap_size) && ((h->heap[child].key) < h->heap[child + 1].key)) {
      child++;
    }
    if (temp.key >= h->heap[child].key) {
      break;
    }
    h->heap[parent] = h->heap[child];
    parent = child;
    child *= 2;
  }
  h->heap[parent] = temp;
  return item;
}

int main (void) {
  element e1 = {10}, e2 = {5}, e3 = {30};
  element e4, e5, e6;
  HeapType heap;

  init(&heap);
  insert_max_heap(&heap, e1);
  insert_max_heap(&heap, e2);
  insert_max_heap(&heap, e3);
  
  printf("<%d> <%d> <%d>\n", e1.key, e2.key, e3.key);
  printf("<%d> <%d> <%d>\n", heap.heap[1].key, heap.heap[2].key, heap.heap[3].key);

  e4 = delete_max_heap(&heap);
  e5 = delete_max_heap(&heap);
  e6 = delete_max_heap(&heap);

  printf("<%d> <%d> <%d>\n", e4.key, e5.key, e6.key);
  return 0;
}


