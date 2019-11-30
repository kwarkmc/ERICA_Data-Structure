#include <stdio.h>
#include <time.h>

int fib(int);
int fib_iter(int);

int main (void) {
  clock_t start, finish;
  double duration;
  int n, i, result;

  printf("input n : ");
  scanf("%d", &n);
  start = clock();
  for (i=0;i<10;i++){
    result = fib(n);
    printf("fib(%d) = %d\n", n, result);
  }
  finish = clock();

  duration = (double)(finish-start)/CLOCKS_PER_SEC;
  printf("%f seconds\n", duration);
  return 0;
}
/*
int fib_iter(int n) {
  if (n<2)
    return n;
  else {
    int i, tmp, current=1, last=0;
    for (int i = 2;i<=n;i++) {
      tmp = current;
      current += last;
      last = tmp;
    }
    return current;
  }
}
*/
int fib(int n) {
if (n==0) 
  return 0;
else if (n==1)
  return 1;
else 
  return (fib(n-1) + fib(n-2));
}

