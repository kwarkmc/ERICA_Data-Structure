#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef int element;
typedef struct {
  element queue[MAX_QUEUE_SIZE];
  int front, rear;
} QueueType;

void init(QueueType *q) {
  q->front = q->rear = 0;
}

int is_empty(QueueType *q) {
  return (q->front == q->rear);
}

int is_full(QueueType *q) {
  return (q->front == (q->rear + 1) % MAX_QUEUE_SIZE);
}

void enqueue (QueueType *q, element item) {
  if(is_full(q) == 1) {
    fprintf(stderr, "큐포화에러\n");
    exit(1);
  }
  q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
  q->queue[q->rear] = item;
}

element dequeue(QueueType *q) {
  if(is_empty(q) == 1) {
    fprintf(stderr, "큐공백에러\n");
    exit(1);
  }
  q->front = (q->front + 1) % MAX_QUEUE_SIZE;
  return q->queue[q->front];
}

int main (void) {
  QueueType q;
  init(&q);
  enqueue(&q, 1);
  printf("%d\n", dequeue(&q));

  return 0;
}
