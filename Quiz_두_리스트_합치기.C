#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
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
ListNode* concat_list(ListNode* head1, ListNode* head2) {
	if (head1 == NULL) {
		return head2;
	}
	else if (head2 == NULL) {
		return head1;
	}
	else {
		ListNode* p; //노드를 가리키는 구조체 p선언
		p = head1; // p는 head1을 가리키고
		while (p->link != NULL) { //만약 첫번째 리스트를 돌면서(null이 아닐때까지)
			p = p->link;	// p에다가는 p->link를 대입한다
		}
		p->link = head2; //그리고 끝까지 갔으면 마지막 p->link를 리스트2에다가 연결!!
		return head1;
	}
}
int main(void) {
	ListNode* head1 = NULL;
	ListNode* head2 = NULL;

	head1 = insert_first(head1, 10);
	head1 = insert_first(head1, 20);
	head1 = insert_first(head1, 30);
	print_list(head1);

	head2 = insert_first(head2, 40);
	head2 = insert_first(head2, 50);
	print_list(head2);


	ListNode* head3 = concat_list(head1, head2);
	print_list(head3);


	return 0;
}
