#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
  int data;
  struct TreeNode *left, *right;
  int is_thread;
} TreeNode;

TreeNode *find_successor(TreeNode *t) {
  TreeNode *pright = t->right;

  if(pright == NULL || t->is_thread == 1)
    return pright;

  while (pright->left != NULL)
    pright = pright->left;

  return pright;
}

void thread_inorder(TreeNode *t) {
  TreeNode *r;
  r=t;
  while (r->left != NULL)
    r = r->left;
  do {
    printf("%c", r->data);
    r = find_successor(r);
  } while (r != NULL);
}

TreeNode n1 = {'A', NULL, NULL, 1};
TreeNode n2 = {'B', NULL, NULL, 1};
TreeNode n3 = {'C', &n1, &n2, 0};
TreeNode n4 = {'D', NULL, NULL, 1};
TreeNode n5 = {'E', NULL, NULL, 0};
TreeNode n6 = {'F', &n4, &n5, 0};
TreeNode n7 = {'G', &n3, &n6, 0};
TreeNode *exp = &n7;

void main() {
  n1.right = &n3;
  n2.right = &n7;
  n4.right = &n6;

  thread_inorder(exp);
}
