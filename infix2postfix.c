#include <stdio.h>
#include <string.h>

// arraystack3.c

#include <stdio.h>

#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
  element stack[MAX_STACK_SIZE];
  int top;
} StackType;

//스택초기화 함수
void init (StackType *s) {
  s->top = -1;
}
//공백 상태 검출 함수
int is_empty (StackType *s) {
  return (s->top == -1);
}
//포화 상태 검출 함수
int is_full (StackType *s) {
  return (s->top == (MAX_STACK_SIZE -1 ));
}
//삽입함수
void push (StackType *s, element item) {
  if (is_full(s)) {
    fprintf(stderr, "스택포화에러\n");
    return;
  }
  else {
    s->stack[++(s->top)] = item;
  }
}
//삭제함수
element pop (StackType *s) {
  if (is_empty(s)) {
    fprintf(stderr, "스택공백에러\n");
    exit(1);
  }
  else {
    return s->stack[(s->top)--];
  }
}
//피크함수
element peek(StackType *s) {
  if (is_empty(s)) {
    fprintf(stderr, "스택공백에러\n");
    exit(1);
  }
  else {
    return (s->stack[s->top]);
  }
}

//연산자의 우선순위를 반환한다.
int prec(char op) {
  switch(op) {
    case '(': case')': return 0;
    case '+': case '-': return 1;
    case '*' : case '/' : return 2;
  }
  return -1;
}

//중위 표기 수식 -> 후위 표기 수식
void infix_to_postfix (char exp[]) {
  int i = 0;
  char ch, top_op;
  int len = strlen(exp);
  StackType s;
  
  init(&s);
  for (i=0;i<len;i++) {
    ch = exp[i];
    switch (ch) {
      case '+': case '-': case'*': case'/':
        while (!is_empty(&s) && (prec(ch)) <= prec(peek(&s)))
          printf("%c", pop(&s));
        push(&s, ch);
        break;
      case '(':
        push(&s, ch);
        break;
      case')':
        top_op = pop(&s);
        while(top_op != '(') {
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

void main() {
  infix_to_postfix("(2+3)*4+9");
}
