#include <stdio.h>
#include <time.h>

int get_integer(void);
int power (int x, int y);

int main (void) {
  clock_t start, finish;
  double duration;
  int a, b, p;

  a = get_integer();
  b = get_integer();

  start = clock();
  p = power(a,b);
  finish = clock();
  duration = (double)(finish - start) / CLOCKS_PER_SEC;

  printf("%d power %d is %d. \n", a, b, p);
  printf("%f seconds\n", duration);

  return 0;
}

int get_integer(void) {
  int temp;
  printf("insert the number : ");
  scanf("%d", &temp);
  return temp;
}

int power (int x, int y) {
  int result = 1;
  for (int i = 0; i<y; i++) {
    result = result * x;
  }
  return result;
}
