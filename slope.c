#include <stdio.h>

typedef struct {
  int x;
  int y;
} PointType;

int get_line_parameter (PointType p1, PointType p2, float *slope, float *yintcpt) {
if (p1.x == p2.x || p1.y == p2.y)
  return -1;
else {
  *slope = (p2.y-p1.y)/(p2.x-p1.x);
  *yintcpt = p2.y - *slope * p2.x;
  return 0;
}
}

int main (void) {
  PointType pt1 = {3,3}, pt2 = {6,6};
  float s, y;
  if (get_line_parameter(pt1, pt2, &s, &y) == -1) {
    printf("error\n");
  }
  else 
    printf("Slope = %f, yintercept = %f\n", s, y);
  return 0;
}
