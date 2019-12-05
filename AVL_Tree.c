#include <stdio.h>
#include <stdlib.h>

#define TRUE 1;
#define FALSE 0;

typedef struct {
  int key;
} element;

typedef struct treeNode *treePointer;

struct treeNode {
  treePointer leftChild;
  element data;
  int bf;
  treePointer rightChild;
} treeNode;

void leftRotation(treePointer *parent, int *unbalanced) {
  treePointer grandChild, child;
  child = (*parent)->leftChild;
  if(child->bf == 1) {
    //LL Rotation
    (*parent)->leftChild = *parent;
    (*parent)->bf = 0;
    (*parent) = child;
  }
  else {
    //LR Rotation
    grandChild = child->rightChild;
    child->rightChild = grandChild->leftChild;
    grandChild->leftChild = child;
    (*parent)->leftChild = grandChild->rightChild;
    grandChild->rightChild = *parent;
    switch(grandChild->bf) {
      case 1:
        (*parent)->bf = -1;
        child->bf = 0;
        break;
      case 0:
        (*parent)->bf = child->bf = 0;
        break;
      case -1:
        (*parent)->bf = 0;
        child->bf = 1;
        break;
    }
    *parent = grandChild;
  }
  (*parent)->bf = 0;
  *unbalanced = FALSE;
}

void rightRotation(treePointer *parent, int *unbalanced) {

}
void avlinsert(treePointer *parent, element x, int *unbalanced) {
  if(!*parent) {
    *unbalanced = TRUE;
    *parent = (treePointer)malloc(sizeof(treeNode));
    (*parent)->leftChild = (*parent)->rightChild = NULL;
    (*parent)->bf = 0;
    (*parent)->data = x;
  }
  else if (x.key < (*parent)->data.key) {
    avlinsert(&(*parent)->leftChild, x, unbalanced);
    if(*unbalanced) {
      switch((*parent)->bf) {
        case 1:
          (*parent)->bf = 0;
          *unbalanced = FALSE;
          break;
        case 0:
          (*parent)->bf = 1;
          break;
        case -1:
          leftRotation(parent, unbalanced);
          break;
      }
    }
  }
  else {
    *unbalanced = FALSE;
    printf("The key is already int the tree\n");
  }
}

void menu() {
  printf("Insert 'i'\n");
  printf("EXIT 'e'\n");
}

int main(void) {
  int unbalanced;
  char input[2];
  treePointer root = NULL;
  element x;
  while(1) {
    menu();
    scanf("%s", input);
    switch(*input) {
      case 'i':
        printf("Please enter an number : \n");
        scanf("%d", &x.key);
        avlinsert(&root, x, &unbalanced);
        break;
      case 'e':
        return 0;
        break;
      default:
        printf("Unknown Comman\n");
    }
  }
  return 0;
}
