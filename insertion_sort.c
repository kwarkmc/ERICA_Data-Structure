#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX_SIZE 10000
#define SWAP(x, y, temp) ((temp)=(x), (x)=(y), (y)=(temp))

void insertion_sort(int list[], int n) {
  int i, j, key;

  for (i = 1; i<n; i++) {
    key = list[i];

    for (j = i-1; j>=0 && list[j]>key; j--) {
      list[j+1] = list[j];
    }
    list[j+1] = key;
  }
}

int partition(int list[], int left, int right) {
  int pivot, temp;
  int low, high;

  low = left;
  high = right + 1;
  pivot = list[left];

  do {
    do {
      low++;
    } while (low <= right && list[low]<pivot);

    do {
      high--;
    } while (high >= left && list[high]>pivot);

    if (low<high) {
      SWAP(list[low], list[high], temp);
    }
  } while (low<high);

  SWAP(list[left], list[high], temp);

  return high;
}

void quick_sort(int list[], int left, int right) {
  if(left<right) {
    int q = partition(list, left, right);
    quick_sort(list, left, q-1);
    quick_sort(list, q+1, right);
  }
}

void main() {
  int i;
  clock_t start1, finish1;
  double duration1;
  clock_t start2, finish2;
  double duration2;

  int n = MAX_SIZE;
  int list1[MAX_SIZE];
  for (int j = 0; j<10000; j++) {
    list1[j] = rand();
  }
  int list2[MAX_SIZE];
  for (int j = 0; j<10000; j++) {
    list2[j] = list1[j];
  }
  start1 = clock();

  insertion_sort(list1, n);

  finish1 = clock();
  duration1 = (double)(finish1 - start1) / CLOCKS_PER_SEC;

  start2 = clock();

  quick_sort(list2, 0, MAX_SIZE - 1);

  finish2 = clock();

  duration2 = (double)(finish2 - start2) / CLOCKS_PER_SEC;

  for(i = 0; i<n; i++) {
    printf("%d\n", list1[i]);
  }
  printf("%f seconds\n", duration1);
  printf("%f seconds\n", duration2);
}
