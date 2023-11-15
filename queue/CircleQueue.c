#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX 10
typedef int element;
typedef struct {	//큐타입
	int front;
	int rear;
	element data[MAX];
}Queue;

//초기화 함수
void init(Queue* q) {
	q->front = 0;
	q->rear = 0;
}
//공백 상태 검출 함수
int is_empty(Queue* q) {
	if (q->front == q->rear) return 1;
	else return 0;
}
//포화 상태 검출 함수
int is_full(Queue* q) {
	if (q->front == (q->rear + 1) % MAX) return 1;
	else return 0;
}
//큐 출력 함수
void queue_print(Queue* q) {
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
//삽입 함수
void enqueue(Queue* q, element e) {
	if (is_full(q)) {
		fprintf(stderr, "큐가 포화상태입니다.");
	}
	q->data[(++q->rear) % MAX] = e;
}
//제거 함수
element dequeue(Queue* q) {
	if (is_empty(q)) {
		fprintf(stderr, "큐가 비어있습니다.");
	}
	return q->data[(++q->front) % MAX];
}
//큐 원소 출력 함수
element peek(Queue* q) {
	if (is_empty(q)) {
		fprintf(stderr, "큐가 비어있습니다.");
	}
	return q->data[(q->front + 1) % MAX];
}

int main() {
	Queue q;
	element a;

	init(&q);
	printf("--데이터 추가 단계--\n");
	while (!is_full(&q)) {
		printf("정수를 입력하세요 : ");
		scanf("%d", &a);
		enqueue(&q, a);
		queue_print(&q);
	}
	printf("큐는 포화상태입니다.\n\n");

	printf("--데이터 삭제 단계--\n");
	while (!is_empty(&q)) {
		a = dequeue(&q);
		printf("꺼내진 정수 : %d \n", a);
		queue_print(&q);
	}
	printf("큐는 공백상태입니다.\n");

	return 0;
}