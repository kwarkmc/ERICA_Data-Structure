#include <stdio.h>
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MAX_DEGREE 101

typedef struct {
  int degree;
  float coef[MAX_DEGREE];
} polynomial;
polynomial poly_add1 (polynomial A, polynomial B) {
  polynomial C;
  int Apos = 0, Bpos = 0, Cpos = 0;
  int degree_a = A.degree;
  int degree_b = B.degree;
  C.degree = MAX(A.degree, B.degree);
  printf("Calculating ...\n");
  while (Apos <= A.degree && Bpos <= B.degree) {
    if (degree_a > degree_b) {
      C.coef[Cpos++] = A.coef[Apos++];
      degree_a--;
      printf("a position %d \n", degree_a);
    }
    else if (degree_a == degree_b) {
      C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
      degree_a--;
      degree_b--;
      printf("a position %d \n", degree_a);
      printf("b position %d \n", degree_b);
    }
    else {
      C.coef[Cpos++] = B.coef[Bpos++];
      degree_b--;
      printf("b position %d \n", degree_b);
    }
  }
  return C;
}

int main (void) {
  polynomial a = {5, {3,6,0,0,0,10}};
  polynomial b = {4, {7,0,5,0,1}};

  polynomial c;
  c = poly_add1 (a,b);

  for (int i = 0; i <= c.degree; i++)
    printf("%f ", c.coef[i]);
  printf("\n");

  return 0;
}