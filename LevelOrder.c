#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef int element;

typedef struct {
  int data;
  struct TreeNode *left, *right;
} TreeNode;

typedef struct {
  int front, rear;
  element queue[MAX_QUEUE_SIZE];
}QueueType;

typedef TreeNode = *element;

TreeNode n1 = {1, NULL, NULL};
TreeNode n2 = {4, &n1, NULL};
TreeNode n3 = {16, NULL, NULL};
TreeNode n4 = {25, NULL, NULL};
TreeNode n5 = {20, &n3, &n4};
TreeNode n6 = {15, &n2, &n5};
TreeNode *root = &n6;

void error(char *message) {
  fprintf(stderr, "%s\n", message);
  exit(1);
}

void init(QueueType *q) {
  q->front = q->rear = 0;
}

void is_empty(QueueType *q) {
  return (q->front == q->rear);
}

int is_full(QueueType *q) {
  return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void enqueue (QueueType *q, element item) {
  if(is_full(q)) {
    error("Queue is full!");
  }
  q->rear = (q->rear+1)%MAX_QUEUE_SIZE;
  q->queue[q->rear] = item;
}

element dequeue(QueueType *q) {
  if(is_empty(q)) {
    error("Queue is empty!");
  }
  q->front = (q->front+1)%MAX_QUEUE_SIZE;
  return q->queue[q->front];
}

void level_order(TreeNode *ptr) {
  QueueType q;
  init(&q);
  if(ptr == NULL) return;

  enqueue(&q, ptr);

  while (!is_empty(&q)) {
    ptr = dequeue(&q);
    printf("%d", ptr->data);
    if(ptr->left)
      enqueue(&q, ptr->left);
    if(pty->right)
      enqueue(&q, ptr->right);
  }
}
  int main (void) {
    level_order(root);
    return 0;
  }

