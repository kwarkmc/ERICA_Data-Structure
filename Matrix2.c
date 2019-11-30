#include <stdio.h>
#include <stdlib.h>
#define ROWS 3
#define COLS 3
#define MAX_TERMS 10

typedef struct {
  int row;
  int col;
  int value;
} element;

typedef struct SparseMatrix {
  element data[MAX_TERMS];
  int rows;
  int cols;
  int terms;
} SparseMatrix;

SparseMatrix spare_matrix_add2 (SparseMatrix a, SparseMatrix b) {
  SparseMatrix c;
  int ca = 0, cb = 0, cc = 0;

  if (a.rows != b.rows || a.cols != b.cols) {
    fprintf(stderr, "Matrix size error\n");
    exit(1);
  }
  c.rows = a.rows;
  c.cols = a.cols;
  c.terms = 0;

  while (ca < a.terms && cb < b.terms) {
    int inda = a.data[ca].row * a.cols + a.data[ca].col;
    int indb = b.data[cb].row * b.cols + b.data[cb].col;
    printf("inda = %d ind b = %d\n", inda, indb);
    if(inda < indb) {
      c.data[cc++] = a.data[ca++];
      printf("case 1 : cc = %d c.data[cc] = %d\n", cc-1, c.data[cc-1]);
    }
    else if (inda == indb) {
      if((a.data[ca].value + b.data[cb].value) != 0) {
        c.data[cc].row = a.data[ca].row;
        c.data[cc].col = a.data[ca].col;
        c.data[cc++].value = a.data[ca++].value + b.data[cb++].value;
      }
      else {
        ca++;
        cb++;
      }
      printf("case 2 : cc = %d c.data[cc] = %d\n", cc-1, c.data[cc-1]);
    }
    else {
      c.data[cc++] = b.data[cb++];
      printf("case 3 : cc = %d c.data[cc] = %d\n", cc-1, c.data[cc-1]);
    }
  }

  for (; ca < a.terms ;)
    c.data[cc++] = a.data[ca++];
  for (; cb < b.terms ;)
    c.data[cc++] = b.data[cb++];
  c.terms == cc;
  return c;
}

void main() {
  SparseMatrix m1 = {{{1,1,5}, {2,2,9}}, 3,3,2};
  SparseMatrix m2 = {{{0,0,5}, {2,2,9}}, 3,3,2};
  SparseMatrix m3;

  m3 = spare_matrix_add2(m1, m2);
}
