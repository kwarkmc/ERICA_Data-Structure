#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STACK_SIZE 100
#define TRUE 1
#define FALSE 0

typedef int element;

typedef struct {
  int top;
  element stack[MAX_STACK_SIZE];
} StackType;

void init(StackType *s) {
  s->top = -1;
}

int is_Full(StackType *s) {
  if(s->top >= MAX_STACK_SIZE -1)
    return TRUE;
  else
    return FALSE;
}

int is_Empty(StackType *s) {
  if(s->top == -1)
    return TRUE;
  else
    return FALSE;
}

void push (StackType *s, element item) {
  if (is_Full(s))
    printf("스택포화에러\n");
  else {
    s->stack[s->top + 1] = item;
    s->top++;
  }
}

element pop(StackType *s) {
  if(is_Empty(s))
    printf("스택공백에러\n");
  else {
    s->top = s->top - 1;
    return s->stack[s->top + 1];
  }
}

int palindrome (char in_str[]) {
  StackType s;
  int i;
  char ch, chs;
  int len = strlen(in_str);
  init(&s);

  for (i=0;i<len;i++) {
    ch = in_str[i];
    if (ch == ' '||ch == ',')
      continue;
    ch = tolower(ch);
    push(&s, ch);
  }

  for (i=0;i<len;i++) {
    ch = in_str[i];
    if(ch == ' ' || ch == ',')
      continue;
    ch = tolower(ch);
    chs = pop(&s);
    if(ch != chs)
      return FALSE;
    else {
      return TRUE;
    }
  }
}


int main() {
  char str[MAX_STACK_SIZE];
  int check;

  printf("Please enter a string : \n\t");
  fgets(str, MAX_STACK_SIZE, stdin);

  check = palindrome(str);

  if(check)
    printf("The string is a palindrome.\n");
  else {
    printf("The string is not a palindrome.\n");
  }
}


