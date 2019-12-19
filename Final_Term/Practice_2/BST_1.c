#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode {
  char key;
  struct treeNode *left;
  struct treeNode *right;
} treeNode;

typedef char element;

treeNode *insertNode (treeNode *p, char x) {
  treeNode *newNode;
  if(p == NULL) {
    newNode = (treeNode *)malloc(sizeof(treeNode));
    newNode->key = x;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
  }
  else if(p->key > x) p->left = insertNode(p->left, x);
  else if(p->key < x) p->right = insertNode(p->right, x);
  else printf("Same Key already exists!\n");
  return p;
}

treeNode *searchBST(treeNode *root, char x) {
  treeNode *p;
  p = root;
  while (p != NULL) {
    if (x<p->key) p = p->left;
    else if(x>p->key) = p->right;
    else return p;
  }
  printf("\nWhere is no key which you are finding!\n");
  return p;
}

void displayInorder(treeNode *root) {
  if(root) {
    displayInorder(root->left);
    printf("%c_", root->key);
    displayInorder(root->right);
  }
}

treeNode *deleteNode (treeNode **root, char x) {
  treeNode *parent, *p, *succ, *succ_parent;
  treeNode *child;

  parent = NULL;
  p = *root;
  while((p != NULL) && (p->key == key)) {
    parent = p;
    if(key < p->key) p = p->left;
    else p = p->right;
  }
  if(p == NULL) {
    printf("There is no key!\n");
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
  else if((p->left == NULL) || (p->right == NULL)) {
    if(p->left != NULL) child = p->left;
    else child = p->right;

    if(parent != NULL) {
      if(parent->left == p) parent->left = child;
      else parent->right = child;
      free(p);
    }
    else {
      free(p);
      *root = child;
    }
  }
  else {
    succ_parent = p;
    succ = p->left;
    while(succ->right != NULL) {
      succ_parent = succ;
      succ = succ->right;
    }
    if(succ_parent->left == succ) succ_parent->left = succ->left;
    else succ_parent->right = succ->left;
    p->key = succ->key;
    free(succ);
  }
}
