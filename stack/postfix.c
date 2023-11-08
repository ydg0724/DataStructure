#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
int calc(char*);

typedef struct {
	int data[MAX];
	int top;
}Stack;

void init_stack(Stack* s) {	//���� �ʱ�ȭ
	s->top = -1;
}

int is_full(Stack* s) {
	return (s->top == MAX - 1);
}

int is_empty(Stack* s) {
	return (s->top == -1);
}

void push(Stack* s, int item) {
	if (is_full(s)) {
		fprintf(stderr, "���þȿ� ���Ұ� �������ֽ��ϴ�.");
	}
	else s->data[++(s->top)] = item;
}

int pop(Stack* s) {
	if (is_empty(s)) fprintf(stderr, "������ ����ֽ��ϴ�.");
	else return s->data[s->top--];
}

int peek(Stack* s) {
	if (is_empty(s)) fprintf(stderr, "������ ����ֽ��ϴ�.");
	else {
		return s->data[s->top];
	}
}

int main() {
	char* str = "82/3-32*+";
	char* str2 = "(2+3)*4+9";

	int result = calc(str);
	printf("��� ��� : %d", result);

	return 0;
}



int calc(char* str) {
	Stack s;
	init_stack(&s);	//���� �ʱ�ȭ
	int n1, n2;

	int n = strlen(str);
	for (int i = 0; i < n; i++) {
		char ch = str[i];
		if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {	//�������� ���
			n2 = pop(&s);
			n1 = pop(&s);
			switch (ch) {
			case '+': push(&s, n1 + n2); break;
			case '-': push(&s, n1 - n2); break;
			case '*': push(&s, n1 * n2); break;
			case '/': push(&s, n1 / n2); break;
			}
		}
		else {													//�ǿ������� ���
			int num = ch - '0';
			push(&s, num);
		}
	}
	return pop(&s);
}