#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX 10
typedef struct {	//���� Ÿ��
	int data[MAX];
	int top;
}Stack;
//�ʱ�ȭ �Լ�
void init_stack(Stack* s) {	
	s->top = -1;
}
//��ȭ ���� ���� �Լ�
int is_full(Stack* s) {
	return (s->top == MAX - 1);
}
//���� ���� ���� �Լ�
int is_empty(Stack* s) {
	return (s->top == -1);
}
//���� �Լ�
void push(Stack* s,int item) {
	if (is_full(s)) {
		fprintf(stderr, "���þȿ� ���Ұ� �������ֽ��ϴ�.");
	}
	else s->data[++(s->top)] = item;
}
//���� �Լ�
int pop(Stack* s) {
	if (is_empty(s)) fprintf(stderr, "������ ����ֽ��ϴ�.");
	else return s->data[s->top--];
}
//���� ���� ��� �Լ�
int peek(Stack* s) {
	if (is_empty(s)) fprintf(stderr, "������ ����ֽ��ϴ�.");
	else {
		return s->data[s->top];
	}
}

int main() {
	Stack s;

	init_stack(&s);
	push(&s,10);
	push(&s,11);
	push(&s,12);
	printf("%d\n", pop(&s));
	printf("%d\n", peek(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));

	return 0;
}






