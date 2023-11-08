#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
#define SIZE 6

typedef struct {
	short r;
	short c;
}element;

typedef struct {
	element data[MAX];
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

void push(Stack* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "스택안에 원소가 가득차있습니다.");
	}
	else s->data[++(s->top)] = item;
}

element pop(Stack* s) {
	if (is_empty(s)) fprintf(stderr, "스택이 비어있습니다.");
	else return s->data[s->top--];
}

element peek(Stack* s) {
	if (is_empty(s)) fprintf(stderr, "스택이 비어있습니다.");
	else {
		return s->data[s->top];
	}
}


element here = { 1,0 }, entry = { 1,0 };

char maze[SIZE][SIZE] = {
	{'1','1','1','1','1','1'},
	{'e','0','1','0','0','1'},
	{'1','0','0','0','1','1'},
	{'1','0','1','0','1','1'},
	{'1','0','1','0','0','x'},
	{'1','1','1','1','1','1'}
};
void push_loc(Stack* s, int r, int c) {
	if (r < 0 || c < 0) return;
	if (maze[r][c] != '1' && maze[r][c] != '.') {
		element tmp;
		tmp.r = r;
		tmp.c = c;
		push(s, tmp);
	}
}

void maze_print(char maze[SIZE][SIZE]) {
	printf("\n");
	for (int r = 0; r < SIZE; r++) {
		for (int c = 0; c < SIZE; c++) {
			printf("%2c", maze[r][c]);
		}
		printf("\n");
	}
}

int main() {
	int r, c;
	Stack s;
	init_stack(&s);

	here = entry;
	while (maze[here.r][here.c] != 'x') {
		r = here.r;
		c = here.c;
		maze[r][c] = '.';
		maze_print(maze);
		push_loc(&s, r - 1, c);
		push_loc(&s, r + 1, c);
		push_loc(&s, r, c - 1);
		push_loc(&s, r, c + 1);

		if (is_empty(&s)) {
			printf("실패\n");
		}
		else
			here = pop(&s);
	}
	printf("성공\n");
	return 0;
}