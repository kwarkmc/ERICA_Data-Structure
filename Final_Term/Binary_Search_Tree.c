#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
  char key;
  struct TreeNode *left;
  struct TreeNode *right;
} TreeNode;

typedef char element;

TreeNode* insertNode(TreeNode *p, char x) {
  TreeNode *newNode;
  if(p == NULL) {
    newNode = (TreeNode *)malloc(sizeof(TreeNode));
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
    printf("\n 이미 같은 키가 있습니다. \n");
  }
  return p;
}

void deleteNode (TreeNode *root, element key) {
  TreeNode *parent, *p, *succ, *succ_parent;
  TreeNode *child;

  parent = NULL;
  p = root;
  while((p != NULL) && (p->key != key)) {
    parent = p;
    if(key < p->key) {
      p = p->left;
    }
    else {
      p = p->right;
    }
  }
  
  if(p == NULL) {
    printf("찾는 키가 이진 트리에 없습니다.\n");
    return;
  }

  if((p->left == NULL) && (p->right == NULL)) {
    if (parent != NULL) {
      if(parent->left == p) {
        parent->left = NULL;
      }
    }
    else {
      root = NULL;
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
    }
    else {
      root = child;
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
  }
  free(succ);
  printf("a");
}

TreeNode* searchBST(TreeNode *root, char x) {
  TreeNode *p;
  p = root;
  while (p != NULL) {
    if(x<p->key) {
      p = p->left;
    }
    else if (x == p->key) {
      return p;
    }
    else {
      p = p->right;
    }
  }
  printf("찾는 키가 없습니다!");
  return p;
}

void displayInorder(TreeNode* root) {
  displayInorder(root->left);
  printf("%c_", root->key);
  displayInorder(root->right);
}

void menu() {
  printf("\n*-----------------------*");
  printf("\n\t1 : 트리 출력");
  printf("\n\t2 : 문자 삽입");
  printf("\n\t3 : 문자 삭제");
  printf("\n\t4 : 문자 검색");
  printf("\n\t5 : 종료");
  printf("\n*-----------------------*");
  printf("\napsbdlqfur >> ");
}

int main() {
  TreeNode *root = NULL;
  TreeNode *foundedNode = NULL;
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

    switch(choice) {
      case '1':
        printf("\t[이진트리 출력]");
        displayInorder(root);
        printf("\n");
        break;
      case '2':
        printf("삽입할 문자를 입력하세요 : ");
        key = getchar(); getchar();
        insertNode(root, key);
        break;
      case '3':
        printf("삭제할 문자를 입력하세요 : ");
        key = getchar(); getchar();
        deleteNode(root, key);
        break;
      case '4':
        printf("찾을 문자를 입력하세요 : ");
        key = getchar(); getchar();
        foundedNode = searchBST(root, key);
        if(foundedNode != NULL) {
          printf("\n %c를 찾았습니다!", foundedNode->key);
        }
        else {
          printf("\n 문자를 찾지 못했습니다.\n");
        }
        break;
      case '5':
        return 0;
      default:
        printf("없는 메뉴입니다. 메뉴를 다시 선택하세요.\n");
        break;
    }
  }
}
