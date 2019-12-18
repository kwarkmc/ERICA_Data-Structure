#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode {
  char key;
  struct treeNode *left;
  struct treeNode *right;
} treeNode;

typedef char element;

treeNode *insertNode(treeNode *p, char x) {
  treeNode *newNode;
  if(p == NULL) {
    newNode = (treeNode *)malloc(sizeof(treeNode));
    newNode->key = x;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
  }
  else if (x < p->key) {
    p->left = insertNode(p->left, x);
  }
  else if (x > p->key) {
    p->right = insertNode(p->right, x);
  }
  else {
    printf("Same key already exits!\n");
  }
  return p;
}

void deleteNode (treeNode **root, element key) {
  treeNode *parent, *p, *succ, *succ_parent;
  treeNode *child;

  parent = NULL;
  p = *root;

  while ((p != NULL) && (p->key != key)) {
    parent = p;
    if(key < p->key) {
      p = p->left;
    }
    else {
      p = p->right;
    }
  }
  if (p == NULL) {
    printf("There is no key which you are finding in BST!\n");
    return;
  }
  if((p->left == NULL) && (p->right == NULL)) {
    if(parent != NULL) {
      if(parent->left == p) {
        parent->left = NULL;
      }
      else {
        parent->right = NULL;
      }
      free(p);
    }
    else {
      free(p);
      *root = NULL;
    }
  }
  else if((p->left == NULL) || (p->right == NULL)) {
    if(p->left != NULL) {
      child = p->left;
    }
    else {
      child = p->right;
    }

    if(parent != NULL) {
      if(parent->left == p) {
        parent->left = child;
      }
      else {
        parent->right = child;
      }
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
    if(succ_parent->left == succ) {
      succ_parent->left = succ->left;
    }
    else {
      succ_parent->right = succ->left;
    }
    p->key = succ->key;
    free(succ);
  }
}

treeNode *searchBST(treeNode *root, char x) {
  treeNode *p;
  p = root;
  while(p != NULL) {
    if(x<p->key) p = p->left;
    else if (x == p->key) return p;
    else p = p->right;
  }
  printf("\nThere is no key which you are finding!\n");
  return p;
}

void displayInorder(treeNode *root) {
  if(root) {
    displayInorder(root->left);
    printf("%c_", root->key);
    displayInorder(root->right);
  }
}

void menu() {
  printf("\n*------------------------*\n");
  printf("\t1 : Display Tree\n");
  printf("\t2 : Insert Character\n");
  printf("\t3 : Delete character\n");
  printf("\t4 : Serach Character\n");
  printf("\t5 : Exit\n");
  printf("\n*------------------------*\n");
  printf("Select the menu >> ");
}

int main() {
  treeNode *root = NULL;
  treeNode *foundedNode = NULL;
  char choice, key;
  root = insertNode(root, 'G');
  insertNode(root, 'I');
  insertNode(root, 'H');
  insertNode(root, 'D');
  insertNode(root, 'B');
  insertNode(root, 'M');
  insertNode(root, 'N');
  insertNode(root, 'A');
  insertNode(root, 'J');
  insertNode(root, 'E');
  insertNode(root, 'Q');

  while(1) {
    menu();
    choice = getchar(); getchar();

    switch (choice) {
      case'1':
        printf("\t\tDisplay Tree : ");
        displayInorder(root);
        printf("\n");
        break;
      case'2':
        printf("Input character : ");
        key = getchar(); getchar();
        root = insertNode(root, key);
        break;
      case'3':
        printf("\n\tInput character will be deleted : ");
        key = getchar(); getchar();
        deleteNode(&root, key);
        break;
      case'4':
        printf("\n\tInput character will be searched : ");
        key = getchar(); getchar();
        foundedNode = searchBST(root, key);
        if(foundedNode != NULL) {
          printf("\n\tWe found %c!\n", foundedNode->key);
        }
        else {
          printf("We didn't find the character.\n");
        }
        break;
      case'5':
        return 0;
      default:
        printf("\n\tIt is not in menu. Select the menu again!\n");
        break;
    }
  }
}
