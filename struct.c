#include <stdio.h>
#include <string.h>

typedef struct array {
  char name[10];
  int age;
  float height;
} person;

void compare (person a, person b) {
if (a.age < b.age) 
  printf("a.age < b.age\n");
else if (a.age > b.age) 
  printf("a.age > b.age\n");
else 
  printf("a.age = b.age\n");
}

int main (void) {
  person a, b;

  strcpy(a.name, "Alice");
  a.age = 15;
  a.height = 50.5;

  printf("enter b's age : ");
  scanf("%d", &b.age);
  compare (a, b);


  printf("a.age = %d, b.age = %d\n", a.age, b.age);

  return 0;
}
