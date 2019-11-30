#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
typedef int element;
element stack[MAX_STACK_SIZE];
int top = -1; // top 이 stack 의 index.

int is_empty() {
  return (top == -1);
}

int is_full() {
  return (top == (MAX_STACK_SIZE - 1));
}

void push(element item) {
  if (is_full()) {
    printf("스택 포화 에러\n");
    exit(1);
  }
  else stack[++top] = item;
}

element pop() {
  if (is_empty()) {
    printf("스택 공백 에러\n");
  }
  else return stack[top--];
}

element peek() {
  if (is_empty()) {
    printf("스택 공백 에러\n");
    exit(1);
  }
  else return stack[top--];
}

void main() {
  push(1);
  push(2);
  push(3); 
  printf("%d\n", pop());
  printf("%d\n", pop());
  printf("%d\n", pop());
  printf("%d\n", is_empty());
}
