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

HeapType* create() {	//생성함수
	return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType* h) {	//초기화 함수
	h->heap_size = 0;
}

//삽입 함수
void insert_max_head(HeapType* h, element item) {
    int i;
    i = ++(h->heap_size);

    while ((i != 1) && (item.key > h->heap[i / 2].key)) {//부모노드와의 비교 후 스왑
        h->heap[i] = h->heap[i / 2];
        i = i / 2;
    }
    h->heap[i] = item; //모든 연산이 끝난 후 item 삽입
}

//삭제 함수
element delete_max_heap(HeapType* h) {
    int parent, child;
    element item, temp;

    item = h->heap[1];
    temp = h->heap[(h->heap_size)--]; //마지막 배열에 있는 값
    parent = 1;
    child = 2;
    while (child <= h->heap_size) {
        //더 큰 자식의 노드를 찾는다.
        if ((child < h->heap_size) && (h->heap[child].key < h->heap[child + 1].key))
            child++;
        if (temp.key >= h->heap[child].key) break; //부모가 더 크다면 스탑
        //자식이 더 크다면 스왑
        else if (h->heap[child].key > h->heap[parent].key) {
            h->heap[parent].key = h->heap[child].key;
            parent = child;
            child = child * 2;
        }
    }
    h->heap[parent] = temp; //맨처음 복사했던 마지막 노드 삽입
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