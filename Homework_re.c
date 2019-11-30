#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

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
  return (s->top == (MAX_STACK_SIZE-1));
}

void push(StackType *s, element item) {
  if (is_full (s)) {
    fprintf(stderr, "error\n");
    exit(1);
  }
  else
    s->stack[++(s->top)] = item;
}

element pop(StackType *s) {
  if (is_empty(s)) {
    fprintf(stderr, "error\n");
    exit(1);
  }
  else
    return s->stack[(s->top)--];
}

element peek(StackType *s) {
  if(is_empty(s)) {
    fprintf(stderr, "Stack empty error\n");
    exit(1);
  }
  else
    return s->stack[(s->top)--];
}

int palindrome (char str0[]) {
  StackType s;
  char ch, chs;
  int len = strlen(str0);
  init(&s);

  for(int i=0;i<len;i++) {
    ch = str0[i];
    if(ch >= 65 && ch <= 90)
      ch = ch + 32;
    if(ch<65 || ch>90 || ch<97 || ch>122)
      continue;
    else
      push(str0, ch);
  }

  for(int i=0;i<len;i++) {
    ch = str0[i];
    if(ch >= 65 && ch <= 90)
      ch = ch+32;
    if(ch<65 || ch>90 || ch<97 || ch>122)
      continue;
    chs = pop(str0);

    if(ch!=chs)
      return 0;
  }
  return 1;
}

int main(void) {
  char str[MAX_STACK_SIZE];
  int check;

  printf("Please enter a string : \n\t");
  fgets(str, MAX_STACK_SIZE, stdin);

  check = palindrome(str);

  if(check == 1)
    printf("The string is a palindrome\n");
  else
    printf("The string is not a palindrome\n");
}
