#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	ListNode* link;
}ListNode;

ListNode* insert_first(ListNode* head, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}
void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link) {
		printf("%d->", p->data);
	}
	printf("NULL\n");
}
ListNode* reverse(ListNode* head) { //실행결과가 30->20->10->NULL에서 
									//10->20->30->NULL 로 바뀐다!!. NULL위치는 그대로야!!

	ListNode* p, * q, * r; //순회 포인터로 p,q,r을 사용 (맨 마지막이 p임) 
	//p는 역순으로 만들 연결리스트를 가리키고, q는 역순으로 만들 노드를 가리키며, 
	//r은 역순으로 된 연결리스트를 가리킵니다.

	p = head;//P는 역순으로 만들 리스트, head로 초기화
	q = NULL;//Q는 역순으로 만들 노드, 역순으로 만들어질 리스트를 가리킬 예정
	while (p != NULL) {
		r = q; //r은 현재까지 역순으로 만들어진 리스트를 가리킴
		q = p; //q는 현재 노드를 가리킨다
		p = p->link; //p를 다음 노드로 이동시킴으로써 한칸씩 앞으로 이동
		q->link = r;//q가 현재 역순으로 만들어진 리스트의 맨 앞에 노드로 삽입
	}
	return q;
}

int main(void) {
	ListNode* head1 = NULL;
	ListNode* head2 = NULL;

	head1 = insert_first(head1, 10);
	head1 = insert_first(head1, 20);
	head1 = insert_first(head1, 30);
	print_list(head1);  //출력 30->20->10->NULL

	head2 = reverse(head1);
	print_list(head2); //출력 10->20->30->NULL
	return 0;
}
