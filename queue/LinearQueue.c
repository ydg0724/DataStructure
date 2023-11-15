#include <stdio.h>
#define MAX 100
typedef int element;
typedef struct {//큐 타입
	int front;
	int rear;
	element data[MAX];
}queue;
//초기화 함수
void init(queue* q) {
	q->front = -1;
	q->rear = -1;
}
//공백 상태 검출 함수
int is_empty(queue* q) {
	if (q->front == q->rear) return 1;
	else return 0;
}
//포화 상태 검출 함수
int is_full(queue* q) {
	if (q->rear == MAX - 1) return 1;
	else return 0;
}
//삽입 함수
void enqueue(queue* q, element e) {
	if (is_full(q)) {
		fprintf(stderr, "큐가 포화상태입니다.");
	}
	else q->data[++(q->rear)] = e;
}
//삭제 함수
element dequeue(queue* q) {
	if (is_empty(q)) {
		fprintf(stderr, "큐가 비어있습니다.");
	}
	else return q->data[++(q->front)];
}
//큐 원소 출력 함수
element peek(queue* q) {
	if (is_empty(q)) {
		fprintf(stderr, "큐가 비어있습니다.");
	}
	else return q->data[q->front];
}
//큐 출력 함수
void queue_print(queue* q) {
	for (int i = 0; i <= q->rear; i++) {
		if (i<= q->front || i>q->rear) 	printf(" |   ");
		else printf("%d | ", q->data[i]);
	}
	printf("\n");
}

int main() {
	int item;
	queue q;

	init(&q);

	enqueue(&q, 10); queue_print(&q);
	enqueue(&q, 20); queue_print(&q);
	enqueue(&q, 30); queue_print(&q);

	item = dequeue(&q); queue_print(&q);
	item = dequeue(&q); queue_print(&q);
	item = dequeue(&q); queue_print(&q);
	return 0;
}



