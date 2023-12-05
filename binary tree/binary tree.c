#include <stdio.h>

typedef struct node{
	int data;
	struct node* left;
	struct node* right;
}node;

//		n1
//	  /   |
//   n2   n3

int main() {
	node* n1, * n2, * n3;
	n1 = (node*)malloc(sizeof(node));
	n2 = (node*)malloc(sizeof(node));
	n2 = (node*)malloc(sizeof(node));

	n1->data = 10;
	n2->data = 20;
	n3->data = 30;
	n1->left = n2;
	n1->right = n3;
	n2->left = NULL;
	n2->right = NULL;
	n3->left = NULL;
	n3->right = NULL;

	free(n1); free(n2); free(n3);
	return 0;
}