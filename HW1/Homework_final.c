#include <stdio.h>
#define MAX 100

typedef struct Stack{
 char word[MAX];
 int top;
}Stack;

void init(Stack *S){
 S->top = -1;
}

int full(Stack *S){
 return (S->top+1) == MAX;
}

int empty(Stack *S){
 return S->top == -1;
}

void push(Stack *S, char word){
 if(full(S))
 {
  printf("FULL");
 }
 else
 {
  S->top++;
  S->word[S->top] = word;
 }
}

char pop(Stack *S){
 int Temp;
 if(empty(S)){
  printf("EMPTY");
  return 0;
 }
 Temp = S->word[S->top];
 S->top--;
 return Temp;
}

int palindrome(char String[]){
 Stack S;
 int i;
 init(&S);
 for(i = 0; String[i] != 0; i++){
  if(String[i] >= 65 && String[i] <= 90)
   String[i] += 32;
  if(97 >= String[i] || 122 <= String[i])
   break;
  push(&S, String[i]);
 }
 for(i = 0; String[i] != 0; i++){
  if(String[i] >= 65 && String[i] <= 90)
   String[i] += 32;
  if(97 >= String[i] || 122 <= String[i])
   break;
  if(String[i] != pop(&S))
  {
   return 0;
  }
 }
 return 1;
}

int main(void){
 char String[MAX];

 printf("Please enter a string:\n\t");
 fgets(String,MAX,stdin);
 if(palindrome(String))
  printf("The string is a palindrome\n");
 else
  printf("The string is not a palindrome\n");
 return 0;
}
