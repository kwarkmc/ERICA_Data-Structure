#include <stdio.h>
#include <stdlib.h>

typedef struct array {
  int value;
  struct array * link;
} A;

void main() {
  A a,b;
  a.value = 1;
  b.value = 2;
  a.link = &b;
}
