#include <stdio.h>

#define MAX 5
typedef int element;
typedef struct {	//큐타입
	int front;
	int rear;
	element data[MAX];
}deque;

//초기화 함수
void init(deque* q) {
	q->front = 0;
	q->rear = 0;
}
//공백 상태 검출 함수
int is_empty(deque* q) {
	if (q->front == q->rear) return 1;
	else return 0;
}
//포화 상태 검출 함수
int is_full(deque* q) {
	if (q->front == (q->rear + 1) % MAX) return 1;
	else return 0;
}
//큐 출력 함수
void queue_print(deque* q) {
	printf("Queue(front=%d rear=%d) ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % (MAX);
			printf("%d | ", q->data[i]);
			if (i == q->rear) break;
		} while (i != q->front);
	}
	printf("\n");
}
//후단 삽입 함수
void add_rear(deque* q, element e) {
	if (is_full(q)) {
		fprintf(stderr, "큐가 포화상태입니다.");
	}
	q->data[(++q->rear) % MAX] = e;
}
//전단 삽입 함수
void add_front(deque* q, element e) {
	if (is_full(q)) fprintf(stderr, "큐가 포화상태입니다.");
	q->data[q->front] = e;
	q->front = (q->front - 1 + MAX) % MAX;
}
	
//전단 제거 함수
element delete_front(deque* q) {
	if (is_empty(q)) {
		fprintf(stderr, "큐가 비어있습니다.");
	}
	return q->data[(++q->front) % MAX];
}
//후단 제거 함수
element delete_rear(deque* q) {
	if (is_empty(q)) fprintf(stderr, "큐가 비어있습니다.");
	q->rear = (q->rear - 1 + MAX) % MAX;
	return q->data[q->rear];
}
//큐 전단 원소 출력 함수
element get_front(deque* q) {
	if (is_empty(q)) {
		fprintf(stderr, "큐가 비어있습니다.");
	}
	return q->data[(q->front + 1) % MAX];
}

element get_rear(deque* q) {
	if (is_empty(q)) fprintf(stderr, "큐가 비어있습니다.");
	return q->data[(q->rear + 1) % MAX];
}


int main() {
	deque q;

	init(&q);
	for (int i = 0; i < 3; i++) {
		add_front(&q, i);
		queue_print(&q);
	}
	for (int i = 0; i < 3; i++) {
		delete_rear(&q);
		queue_print(&q);
	}
	return 0;
}