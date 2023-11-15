#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX 10
typedef struct {	//스택 타입
	int data[MAX];
	int top;
}Stack;
//초기화 함수
void init_stack(Stack* s) {	
	s->top = -1;
}
//포화 상태 검출 함수
int is_full(Stack* s) {
	return (s->top == MAX - 1);
}
//공백 상태 검출 함수
int is_empty(Stack* s) {
	return (s->top == -1);
}
//삽입 함수
void push(Stack* s,int item) {
	if (is_full(s)) {
		fprintf(stderr, "스택안에 원소가 가득차있습니다.");
	}
	else s->data[++(s->top)] = item;
}
//제거 함수
int pop(Stack* s) {
	if (is_empty(s)) fprintf(stderr, "스택이 비어있습니다.");
	else return s->data[s->top--];
}
//스택 원소 출력 함수
int peek(Stack* s) {
	if (is_empty(s)) fprintf(stderr, "스택이 비어있습니다.");
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






