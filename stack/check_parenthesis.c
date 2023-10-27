#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int check_matching(char*);

typedef struct {
	char data[MAX];
	int top;
}Stack;

void init_stack(Stack* s) {	//스택 초기화
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
		fprintf(stderr, "스택안에 원소가 가득차있습니다.");
	}
	else s->data[++(s->top)] = item;
}

int pop(Stack* s) {
	if (is_empty(s)) fprintf(stderr, "스택이 비어있습니다.");
	else return s->data[s->top--];
}

int peek(Stack* s) {
	if (is_empty(s)) fprintf(stderr, "스택이 비어있습니다.");
	else {
		return s->data[s->top];
	}
}

int main() {
	
	char* p = "{ A[(i+1)]=0 }";
	if (check_matching(p) == 1) printf("%s 괄호검사성공!", p);
	else printf("%s 괄호검사실패!", p);

	return 0;
}

int check_matching(char* p) {

}

