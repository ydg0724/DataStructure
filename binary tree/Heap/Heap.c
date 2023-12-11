#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENT 100
typedef struct {
	int key;
}element;
typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

HeapType* create() {	//�����Լ�
	return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType* h) {	//�ʱ�ȭ �Լ�
	h->heap_size = 0;
}

//���� �Լ�
void insert_max_head(HeapType* h, element item) {
    int i;
    i = ++(h->heap_size);

    while ((i != 1) && (item.key > h->heap[i / 2].key)) {//�θ������ �� �� ����
        h->heap[i] = h->heap[i / 2];
        i = i / 2;
    }
    h->heap[i] = item; //��� ������ ���� �� item ����
}

//���� �Լ�
element delete_max_heap(HeapType* h) {
    int parent, child;
    element item, temp;

    item = h->heap[1];
    temp = h->heap[(h->heap_size)--]; //������ �迭�� �ִ� ��
    parent = 1;
    child = 2;
    while (child <= h->heap_size) {
        //�� ū �ڽ��� ��带 ã�´�.
        if ((child < h->heap_size) && (h->heap[child].key < h->heap[child + 1].key))
            child++;
        if (temp.key >= h->heap[child].key) break; //�θ� �� ũ�ٸ� ��ž
        //�ڽ��� �� ũ�ٸ� ����
        else if (h->heap[child].key > h->heap[parent].key) {
            h->heap[parent].key = h->heap[child].key;
            parent = child;
            child = child * 2;
        }
    }
    h->heap[parent] = temp; //��ó�� �����ߴ� ������ ��� ����
    return item;
}

int main() {
    element e1 = { 10 }, e2 = { 5 }, e3 = { 30 };
    element e4, e5, e6;

    HeapType* heap = create();
    init(heap);

    insert_max_head(heap, e1);
    insert_max_head(heap, e2);
    insert_max_head(heap, e3);

    e4 = delete_max_heap(heap);
    printf(" < %d > ", e4.key);
    e5 = delete_max_heap(heap);
    printf(" < %d > ", e5.key);
    e6 = delete_max_heap(heap);
    printf(" < %d > ", e6.key);

    free(heap);
    return 0;

}