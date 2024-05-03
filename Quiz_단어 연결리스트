#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct { //배열을 포함하는 구조체
	char name[100];
}element;

typedef struct ListNode { //노드 타입
	element data; //데이터는 배열을 가진 구조체
	struct ListNode* link; //link는 노드를 가리키는 포인터이자 정체는 구조체
}ListNode;

//에러 처리 함수
void error(const char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}
ListNode* insert_first(ListNode* head, element value) {
	//1. 일단 먼저 동적 할당 해줘야지
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head; //헤드 포인터의 값을 복사
	head = p; //헤드 포인터 변경
	return head;
}

void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link) {
		printf("%s->", p->data.name); //data의 타입은 배열이니까 배열에서 name에 접근하기 위해 data.name
	}
	printf("NULL \n");
}

int main(void) {
	ListNode* head = NULL; //헤드는 원칙적으로 이렇게 해주면 됨!!
	element data;

	strcpy_s(data.name, "APPLE");
	head = insert_first(head, data);
	print_list(head);

	strcpy_s(data.name, "KIWI");
	head = insert_first(head, data);
	print_list(head);

	strcpy_s(data.name, "BANANA");
	head = insert_first(head, data);
	print_list(head);

	return 0;
}

