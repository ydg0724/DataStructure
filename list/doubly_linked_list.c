#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct node{
	element data;
	struct node* llink;
	struct node* rlink;
}node;

void insert(node* before, element data) {
	node* tmp = (node*)malloc(sizeof(node));
	tmp->data = data;
	tmp->llink = before;
	tmp->rlink = before->rlink;
	before->rlink->llink = tmp;
	before->rlink = tmp;
}

void deleted(node* head, node* removed) {
	if (removed == head) return;

	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);
}

void init(node* phead) {
	phead->llink = phead;
	phead->rlink = phead;
}

void print_dlist(node* phead) {
	node* p;
	for (p = phead->rlink; p != phead; p = p->rlink) {
		printf("<- | |%d| |-> ", p->data);
	}
	printf("\n");
}

int main() {
	node* head = (node*)malloc(sizeof(node));
	init(head);
	printf("삽입 단계\n");
	for (int i = 0; i < 5; i++) {
		insert(head, i);
		print_dlist(head);
	}

	printf("\n삭제단계\n");
	for (int i = 0; i < 5; i++) {
		print_dlist(head);
		deleted(head, head->rlink);
	}
	free(head);
}