#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
  int data;
  struct TreeNode *left, *right;
} TreeNode;

void main() {
  TreeNode *n1 = (TreeNode *)malloc(sizeof(TreeNode));
  TreeNode *n2 = (TreeNode *)malloc(sizeof(TreeNode));
  TreeNode *n3 = (TreeNode *)malloc(sizeof(TreeNode));

  n1->data = 10;
  n2->data = 20;
  n3->data = 30;

  n1->left = n2;
  n1->right = n3;

  n2->left = NULL;
  n2->right = NULL;

  n3->left = NULL;
  n3->right = NULL;

  printf("n1 child : %d  %d\n", n1->left->data, n1->right->data);

  free(n1);
  free(n2);
  free(n3);
}
