#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX 10
typedef int element;
typedef struct {	//ťŸ��
	int front;
	int rear;
	element data[MAX];
}Queue;

//�ʱ�ȭ �Լ�
void init(Queue* q) {
	q->front = 0;
	q->rear = 0;
}
//���� ���� ���� �Լ�
int is_empty(Queue* q) {
	if (q->front == q->rear) return 1;
	else return 0;
}
//��ȭ ���� ���� �Լ�
int is_full(Queue* q) {
	if (q->front == (q->rear + 1) % MAX) return 1;
	else return 0;
}
//ť ��� �Լ�
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
//���� �Լ�
void enqueue(Queue* q, element e) {
	if (is_full(q)) {
		fprintf(stderr, "ť�� ��ȭ�����Դϴ�.");
	}
	q->data[(++q->rear) % MAX] = e;
}
//���� �Լ�
element dequeue(Queue* q) {
	if (is_empty(q)) {
		fprintf(stderr, "ť�� ����ֽ��ϴ�.");
	}
	return q->data[(++q->front) % MAX];
}
//ť ���� ��� �Լ�
element peek(Queue* q) {
	if (is_empty(q)) {
		fprintf(stderr, "ť�� ����ֽ��ϴ�.");
	}
	return q->data[(q->front + 1) % MAX];
}

int main() {
	Queue q;
	element a;

	init(&q);
	printf("--������ �߰� �ܰ�--\n");
	while (!is_full(&q)) {
		printf("������ �Է��ϼ��� : ");
		scanf("%d", &a);
		enqueue(&q, a);
		queue_print(&q);
	}
	printf("ť�� ��ȭ�����Դϴ�.\n\n");

	printf("--������ ���� �ܰ�--\n");
	while (!is_empty(&q)) {
		a = dequeue(&q);
		printf("������ ���� : %d \n", a);
		queue_print(&q);
	}
	printf("ť�� ��������Դϴ�.\n");

	return 0;
}