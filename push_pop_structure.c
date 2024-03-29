#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
  element stack [MAX_STACK_SIZE];
  int top;
} StackType;

//stack initialization
void init (StackType *s) {
  s->top = -1;
}

//check empty state of stack
int is_empty (StackType *s) {
  return (s->top == -1);
}

//check full state of stack
int is_full (StackType *s) {
  return (s->top == (MAX_STACK_SIZE-1));
}

//add an item
void push (StackType *s, element item) {
  if (is_full(s)) {
    fprintf (stderr, "스택포화에러\n");
    return;
  }
  else
    s->stack[++(s->top)] = item;
}

//delete top item
element pop (StackType *s) {
  if(is_empty(s)) {
    fprintf(stderr, "스택공백에러\n");
    exit(1);
  }
  else
    return s->stack[(s->top)--];
}

//peek
element peek (StackType *s) {
  if (is_empty(s)) {
    fprintf(stderr, "스택공백에러\n");
    exit(1);
  }
  else return s->stack[s->top];
}

int main() {
  StackType s;

  init(&s);
  push(%s, 1);
  push(%s, 2);
  push(%s, 3);
}
