#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int check_matching(char*);

typedef struct {
	char data[MAX];
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
	
	char* p = "{ A[(i+1)]=0 }";
	if (check_matching(p) == 1) printf("%s ��ȣ�˻缺��!", p);
	else printf("%s ��ȣ�˻����!", p);

	return 0;
}

int check_matching(char* p) {

}

