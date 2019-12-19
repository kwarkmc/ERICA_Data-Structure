#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode {
  char key;
  treeNode *left;
  treeNode *right;
} treeNode;

typedef char element;

treeNode *insertNode (treeNode *p, char x) {
  treeNode *newNode;
  if(p == NULL) {
    newNode = (treeNode *)malloc(sizeof(treeNode));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->key = x;
    return newNode;
  }
  else if (p->key > x) {
    p->left = insertNode(p->left, x);
  }
  else if (p->key < x) {
    p->right = insertNode(p->right, x);
  }
  else {
    printf("Same key already exit!\n");
  }

  return p;
}

treeNode *deleteNode (treeNode **root, char x) {
  treeNode *parent, *p, *succ, *succ_parent;
  treeNode *child;

  parent = NULL;
  p = *root;

  while((p != NULL) && (p->key != key)) {
    parent = p;
    if(key < p->key) p = p->left;
    else p = p->right;
  }
  if(p == NULL) {
    printf("There is no key which you are finding in BST!!\n");
    return;
  }
  if((p->left == NULL) && (p->right == NULL)) {
    if(parent != NULL) {
      if(parent->left == p) parent->left = NULL;
      else parent->right = NULL;
      free(p);
    }
    else {
      free(p);
      *root = NULL;
    }
  }
  else if()
}
