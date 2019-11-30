#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STACK_SIZE 100
#define FALSE 0
#define TRUE 1

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
  return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType *s, element item) {
  if(is_full(s) == 1) {
    fprintf(stderr, "스택포화에러\n");
    exit(1);
  }
  else
    s->stack[++(s->top)] = item;
}

element pop(StackType *s) {
  if(is_empty(s) == 1) {
    fprintf(stderr, "스택공백에러\n");
    exit(1);
  }
  else
    return (s->stack[(s->top)--]);
}

element peek(StackType *s) {
  if(is_empty(s) == 1) {
    fprintf(stderr, "스택공백에러\n");
    exit(1);
  }
  else
    return (s->stack[s->top]);
}

int palindrome(char st[]) {
  StackType s;
  char put;
  char out;
  int len = strlen(st);
  init(&s);
  
  for (int i = 0;i<len;i++) {
    put = st[i];
    if (put == ' '||put == ','||put == '.'||put == '!'||put == '?')
      continue;
    put = tolower(put);
    push(&s, put);
  }

  for(int j = 0;j<len;j++) {
    put = st[j];
    if(put == ' '||put == ','||put == '.'||put == '!'||put == '?')
      continue;
    put = tolower(put);
    out = pop(&s);
    if(put != out)
      return FALSE;
  }
  return TRUE;
}

int main() {
  char st[MAX_STACK_SIZE];
  int check;

  printf("Please enter a string\n");
  gets(st);
  printf("\n");
  check = palindrome(st);

  if(check) {
    printf("The string is palindrome\n");
  }
  else
    printf("The string is not a palindrome\n");
}
