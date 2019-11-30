#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef int element;
element stack[MAX_STACK_SIZE];
int top = -1;

int is_empty() {
  return (top == -1);
}

int is_full() {
  return (top == MAX_STACK_SIZE - 1);
}

void push(element item) {
  if (is_full() == 1) {
    fprintf(stderr, "스택포화에러\n");
    return; // 왜 return?
  }
  else
    stack[++top] = item; // 왜 ++top?
}

element pop() {
  if(is_empty() == 1) {
    fprintf(stderr, "스택공백에러\n");
    exit(1);
  }
  else
    return stack[top--];
}

element peek() {
  if(is_empty() == 1) {
    fprintf(stderr, "스택공백에러\n");
    exit(1);
  }
  else
    return stack[top];
}

//메인 함수

void main(void) {
  push(1);
  push(2);
  push(3);
  printf("%d\n", pop());
  printf("%d\n", pop());
  printf("%d\n", pop());
  printf("%d\n", is_empty());
}
