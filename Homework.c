#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STACK_SIZE 100
#define FALSE 0
#define TRUE 1

typedef int element;

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

void push (StackType *s, element item) {
  if (is_full(s)) {
    fprintf(stderr, "스택 포화 에러.\n");
    return;
  }
  else s->stack[++(s->top)] = item;
}

element peek(StackType *s) {
  if(is_empty(s)) {
    fprintf(stderr, "스택공백에러.\n");
  }
  else {
    return s->stack[s->top];
  }
}

element pop(StackType *s) {
  if (is_empty(s)) {
    fprintf(stderr, "스택공백에러.\n");
  }
  else return s->stack[(s->top)--];
}

int palindrome (char in_str[]) {
  StackType s;
  int i;
  char ch, chs;
  int len = strlen (in_str);
  init(&s);

  for (i=0;i<len;i++) {
    ch = in_str[i];
    if (ch == ' '||ch == ',') continue;
    ch = tolower(ch);
    push(&s, ch);
  }

  for (i=0;i<len;i++) {
    ch=in_str[i];
    if(ch == ' '||ch == ',') continue;
    ch = tolower(ch);
    chs = pop(&s);
    if(ch != chs) return FALSE;
  }
  return TRUE;
}

int main() {
  char str[MAX_STACK_SIZE];
  int check;

  printf("Please enter a string : \n\t");
  fgets(str,MAX_STACK_SIZE,stdin);

  check = palindrome(str);

  if (check)
    printf("The string is a palindrome.\n");
  else
    printf("The string is not a palindrome.\n");
}
