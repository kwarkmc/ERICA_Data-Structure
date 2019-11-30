#include <stdio.h>
#include <time.h>

unsigned int factorial(unsigned int);

int main () {
  clock_t start, finish;
  double duration;
  unsigned int n, fac;

  printf("input n : ");
  scanf("%d", &n);

  start = clock();
  fac = factorial(n);
  finish = clock();

  duration = (double)(finish - start) / CLOCKS_PER_SEC;
  printf("%d! = %d\n", n, fac);
  printf("%f seconds\n", duration);

  return 0;
}

unsigned int factorial(unsigned int n) {
  if (n==1)
    return 1;
  else
    return factorial(n-1);
}
