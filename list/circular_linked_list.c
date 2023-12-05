#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct {
	element data;
	struct node* link;
}node;

void error(char* message) {
	fprintf(stderr, "%s\n", message);
}

node* insert_first(node* head, element value) {
	node* tmp = (node*)malloc(sizeof(node));
	tmp->data = value;
	if (head == NULL) {
		head = tmp;
		tmp->link = head;
	}
	else {
		tmp->link = head->link;
		head->link = tmp;
	}
	return head;
}

node* insert_last(node* head, element value) {
	node* tmp = (node*)malloc(sizeof(node));
	tmp->data = value;
	if (head == NULL) {
		head = tmp;
		tmp->link = head;
	}
	else {
		tmp->link = head->link;
		head->link = tmp;
		head = tmp;
	}
	return head;

}

node* insert(node* head, node* pre, element value) {
	node* tmp = (node*)malloc(sizeof(node));
	tmp->data = value;
	tmp->link = pre->link;
	pre->link = tmp;
	return head;
}

node* delete_first(node* head) {
	head = head->link;
	return head;
}

node* delete(node* head, node* pre) {
	node* tmp = pre->link;
	pre->link = tmp->link;
	free(tmp);
	return head;
}

void print_list(node* head) {
	node* tmp = head->link;
	do {
		printf("%d -> ", tmp->data);
		tmp = tmp->link;
	}while (tmp != head);
	printf("%d -> ",tmp->data);
}

int main() {
	node* head = NULL;

	head = insert_last(head, 20);
	head = insert_last(head, 30);
	head = insert_last(head, 40);
	head = insert_first(head, 10);
	print_list(head);

	return 0;
}

