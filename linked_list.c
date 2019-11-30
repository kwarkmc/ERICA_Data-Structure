#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
  element data;
  struct ListNode* link;
}ListNode;

ListNode* create_node(element data) {
  ListNode* new_node; //new_node는 포인터로 선언되어있음. 주소를 반환하니까 ListNode*로 지정.
  new_node = (ListNode*)malloc(sizeof(ListNode));

  new_node->data = data;
  new_node->link = NULL;

  return new_node;
}

//phead : 리스트의 헤드 포인터의 포인터
//p : 선행 노드
//new_node : 삽입될 노드

void insert_node (ListNode** phead, ListNode* p, ListNode* new_node) { // 왜 더블 포인터를 썼는가? -> head는 주소가 바뀔 수 있다. [포인터 주소의 포인터]
  if (*phead == NULL) { //공백 리스트의 경우
    new_node->link = NULL;
    *phead = new_node;
  }
  else if (p == NULL) { //p가 NULL 이면 첫 번째 노드로 삽입한다.
    new_node->link = *phead;
    *phead = new_node;
  }
  else { // p 다음에 삽입한다.
    new_node->link = p->link;
    p->link = new_node;
  }
}

//phead : 헤드 포인터에 대한 포인터
//p : 삭제될 노드의 선행 노드
//removed : 삭제될 노

void remove_node (ListNode** phead, ListNode* p, ListNode* removed) {
  if (p==NULL)
    *phead = (*phead)->link;
  else {
    p->link = removed->link;
  }
  free(removed);
}

void display(ListNode* head) {
  ListNode* p = head;

  while (p != NULL) {
    printf("%d->", p->data);
    p=p->link;
  }
  printf("\n");
}
void display_recur(ListNode* head) {
  ListNode* p = head;

  if (p==NULL) {
    printf("%d->", p->data);
    display_recur(p->link);
  }
}

ListNode* search(ListNode* head, int x) {
  ListNode* p;
  p = head;

  while (p != NULL) {
    if (p->data == x) return p;
    p = p->link;
  }
  return p;
}

ListNode* concat(ListNode* head1, ListNode* head2) {
  ListNode* p;

  if(head1 == NULL) return head2;
  else if (head2 == NULL) return head1;
  else {
    p = head1;
    while (p->link != NULL)
      p = p->link;
    p->link = head2;

    return head1;
  }
}

ListNode* reverse(ListNode* head) {
  ListNode* p;
  ListNode* q;
  ListNode* r;
  //순회 포인터로 p, q, r을 사용한다.
  p = head; // p 는 아직 처리되지 않은 노드
  q = NULL; // q 는 역순으로 만들 노드

  while (p != NULL) {
    r = q; //r 은 역순으로 된 노드. r은 q, q는 p를 차례로 따라간다.
    q = r;
    p = p->link;
    q->link = r; // q의 링크 방향을 바꾼다.
  }
  return q; //q 는 역순으로 된 리스트의 헤드 포인터
}

int main() {
  ListNode* head1 = NULL;
  ListNode* head2 = NULL;
  ListNode* head3 = NULL;

  insert_node(&head1, head1, create_node(10));
  display(head1);
  insert_node(&head1, search(head1, 10), create_node(20));
  insert_node(&head1, search(head1, 20), create_node(30));
  display(head1);
  remove_node(&head1, search(head1, 20), search(head1, 30));
  display(head1);

  insert_node(&head2, head2, create_node(40));
  display(head2);

  head3 = concat(head1, head2);
  display(head3);

  return 0;
}
