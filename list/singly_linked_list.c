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
	tmp->link = head;
	head = tmp;
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
	node* tmp = head;
	while (tmp != NULL) {
		printf("%d -> ", tmp->data);
		tmp = tmp->link;
	}
	printf("NULL \n");
}

int main() {
	node* head = NULL;

	for (int i = 0; i < 5; i++) {
		head = insert_first(head, i);
		print_list(head);
	}
	for (int i = 0; i < 5; i++) {
		head = delete_first(head);
		print_list(head);
	}

	return 0;
}

