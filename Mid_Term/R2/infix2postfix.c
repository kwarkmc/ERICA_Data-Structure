#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

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

void push(StackType *s, element item) {
  if(is_full(s)) {
    fprintf(stderr, "스택포화에러\n");
    exit(1);
  }
  else
    s->stack[++(s->top)] = item;
}

element pop(StackType *s) {
  if(is_empty(s)) {
    fprintf(stderr, "스택공백에러\n");
    exit(1);
  }
  else
    return s->stack[(s->top)--];
}

element peek(StackType *s) {
  if (is_empty(s)) {
    fprintf(stderr, "스택공백에러\n");
    exit(1);
  }
  else
    return s->stack[s->top];
}

int prec(char op) {
  switch(op) {
    case'(':case')':
      return 0;
    case'+':case'-':
      return 1;
    case'*':case'/':
      return 2;
  }
  return -1;
}

void infix_to_postfix(char exp[]) {
  char ch, top_op;
  int len = strlen(exp);
  StackType s;

  init(&s);

  for(int i = 0;i<len;i++) {
    ch = exp[i];
    switch (ch) {
      case'+':case'-':case'*':case'/':
        while(!is_empty(&s) && (prec(ch) <= prec(peek(&s))))
          printf("%c", pop(&s));
        push(&s, ch);
        break;
      case'(':
        push(&s, ch);
        break;
      case')':
        top_op = pop(&s);
        while (top_op != '(') {
          printf("%c", top_op);
          top_op = pop(&s);
        }
        break;
      default:
        printf("%c", ch);
        break;
    }
  }
  while (!is_empty(&s))
    printf("%c", pop(&s));
}

int main(void) {
  infix_to_postfix("(2+3)*4+9");
}
