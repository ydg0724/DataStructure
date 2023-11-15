#include <stdio.h>
#define MAX 100
typedef int element;
typedef struct {//ť Ÿ��
	int front;
	int rear;
	element data[MAX];
}queue;
//�ʱ�ȭ �Լ�
void init(queue* q) {
	q->front = -1;
	q->rear = -1;
}
//���� ���� ���� �Լ�
int is_empty(queue* q) {
	if (q->front == q->rear) return 1;
	else return 0;
}
//��ȭ ���� ���� �Լ�
int is_full(queue* q) {
	if (q->rear == MAX - 1) return 1;
	else return 0;
}
//���� �Լ�
void enqueue(queue* q, element e) {
	if (is_full(q)) {
		fprintf(stderr, "ť�� ��ȭ�����Դϴ�.");
	}
	else q->data[++(q->rear)] = e;
}
//���� �Լ�
element dequeue(queue* q) {
	if (is_empty(q)) {
		fprintf(stderr, "ť�� ����ֽ��ϴ�.");
	}
	else return q->data[++(q->front)];
}
//ť ���� ��� �Լ�
element peek(queue* q) {
	if (is_empty(q)) {
		fprintf(stderr, "ť�� ����ֽ��ϴ�.");
	}
	else return q->data[q->front];
}
//ť ��� �Լ�
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



