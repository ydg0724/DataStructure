#include <stdio.h>

#define MAX 5
typedef int element;
typedef struct {	//ťŸ��
	int front;
	int rear;
	element data[MAX];
}deque;

//�ʱ�ȭ �Լ�
void init(deque* q) {
	q->front = 0;
	q->rear = 0;
}
//���� ���� ���� �Լ�
int is_empty(deque* q) {
	if (q->front == q->rear) return 1;
	else return 0;
}
//��ȭ ���� ���� �Լ�
int is_full(deque* q) {
	if (q->front == (q->rear + 1) % MAX) return 1;
	else return 0;
}
//ť ��� �Լ�
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
//�Ĵ� ���� �Լ�
void add_rear(deque* q, element e) {
	if (is_full(q)) {
		fprintf(stderr, "ť�� ��ȭ�����Դϴ�.");
	}
	q->data[(++q->rear) % MAX] = e;
}
//���� ���� �Լ�
void add_front(deque* q, element e) {
	if (is_full(q)) fprintf(stderr, "ť�� ��ȭ�����Դϴ�.");
	q->data[q->front] = e;
	q->front = (q->front - 1 + MAX) % MAX;
}
	
//���� ���� �Լ�
element delete_front(deque* q) {
	if (is_empty(q)) {
		fprintf(stderr, "ť�� ����ֽ��ϴ�.");
	}
	return q->data[(++q->front) % MAX];
}
//�Ĵ� ���� �Լ�
element delete_rear(deque* q) {
	if (is_empty(q)) fprintf(stderr, "ť�� ����ֽ��ϴ�.");
	q->rear = (q->rear - 1 + MAX) % MAX;
	return q->data[q->rear];
}
//ť ���� ���� ��� �Լ�
element get_front(deque* q) {
	if (is_empty(q)) {
		fprintf(stderr, "ť�� ����ֽ��ϴ�.");
	}
	return q->data[(q->front + 1) % MAX];
}

element get_rear(deque* q) {
	if (is_empty(q)) fprintf(stderr, "ť�� ����ֽ��ϴ�.");
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