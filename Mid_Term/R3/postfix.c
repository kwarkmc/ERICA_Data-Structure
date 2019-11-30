#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100
#define TRUE 1
#define FALSE 0

typedef char element;
typedef struct {
  element stack[MAX_STACK_SIZE];
  int top;
} StackType;

void init(StackType *s) {
  s->top = -1;
}

int is_empty(StackType *s) {
  return (s->top == -1);
}

int is_full(StackType *s) {
  return s->top == (MAX_STACK_SIZE - 1);
}

void push(StackType *s, element item) {

}
