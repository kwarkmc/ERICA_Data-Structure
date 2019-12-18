#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct {
  int key;
} element;

typedef struct TreeNode *TreePointer;

typedef struct TreeNode {
  TreePointer leftChild;
  element data;
  int bf;
  TreePointer rightChild;
} TreeNode;

void leftRotation (TreePointer *parent, int *unbalanced) {
  TreePointer grandChild, child;
  child = (*parent)->leftChild;
  if(child->bf == 1) {
    //LL Rotation
    (*parent)->leftChild = child->rightChild;
    child->rightChild = *parent;
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
    switch (grandChild->bf) {
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

void rightRotation(TreePointer *parent, int *unbalanced) {
  TreePointer grandChild, child;
  child = (*parent)->rightChild;
  if(child->bf == -1) {
    //RR Rotation
    (*parent)->rightChild = child->leftChild;
    child->leftChild = *parent;
    (*parent)->bf = 0;
    (*parent) = child;
  }
  else {
    //RL Rotation
    grandChild = child->leftChild;
    child->leftChild = grandChild->rightChild;
    grandChild->rightChild = child;
    (*parent)->rightChild = grandChild->leftChild;
    grandChild->leftChild = *parent;
    switch(grandChild->bf) {
      case -1:
        (*parent)->bf = 1;
        child->bf = 0;
        break;
      case 0:
        (*parent)->bf = child->bf = 0;
        break;
      case 1:
        (*parent)->bf = 0;
        child->bf = -1;
        break;
    }
    *parent = grandChild;
  }
  (*parent)->bf = 0;
  *unbalanced = FALSE;
}

void avlinsert(TreePointer *parent, element x, int *unbalanced) {
  if(!*parent) {
    *unbalanced = TRUE;
    *parent = (TreePointer)malloc(sizeof(TreeNode));
    (*parent)->leftChild = (*parent)->rightChild = NULL;
    (*parent)->bf = 0;
    (*parent)->data = x;
  }
  else if(x.key < (*parent)->data.key) {
    avlinsert(&(*parent)->leftChild, x, unbalanced);
    if (*unbalanced) {

    }
  }
}
