# 정렬(sorting)

    정렬은 주어진 데이터를 일전한 기준에 따라 순서대로 나열하는 것이며, 자료 탐색에 있어서 필수적이다.

    정렬의 방법
        - 오름차순(ascending) : 작은 것에서 큰 것으로, 오래된 것부터
        - 내림차순(descending) : 큰 것에서 작은 것으로, 최근 것부터
        - 단일 키(single key) : 하나의 정렬 기준으로
        - 복합 키(multi key) : 두 개 이상의 정렬 기준으로

    - 지금까지 개발된 정렬 알고리즘은 매우 많으며 이 중에서 현재의 프로그램 수행환경에서 가장 효율적인 정렬 알고리즘을 선택해야 한다.
    - 대개 정렬 알고리즘을 평가하는 효율성의 기준으로는 연산 횟수를 빅오 표기법으로 근사적으로 표현한다.

| Algorithm | Average | Worst case | Best case |
| --- | --- | --- | --- |
| 선택 정렬 | O(N^2) | O(N^2) | O(N^2)
| 삽입 정렬 | O(N^2) | O(N^2) | O(N)
| 버블 정렬 | O(N^2) | O(N^2) | O(N^2)

## 선택 정렬

- 전체 원소들 중에서 기준 원소를 선택한 후 교환하는 방식
- 앞(가장 작은 값)에서부터 채워짐

<img src="./img/selection_sort.png" width = 400 height = 500>

```c
void selection_sort(int list[], int n){
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++)
            if(list[i] > list[j]) 
                swap(list[i],list[j]);
    }
}
```

- 원소의 개수가 n일 때 , 일관되게 n(n-1)/2의 시간이 소요됨

## 삽입 정렬
    - 정렬된 부분 집합에 정렬할 새 원소의 위치를 찾아 삽입
    - 전체 원소를 `정렬된 부분 집합`과 `정렬되지 않은 부분 집합`으로 분할

![insertion_sort](./img/insertion_sort.png)

```c
void insertion_sort(int list[],int n){
    int key;
    for(int i=1; i<n; i++){
        key = list[i];
        for(int j=i-1; j>=0 && list[j]>key; j--)
            list[j+1] = list[j];    //레코드의 오른쪽 이동
        list[j+1] = key;
    }
}
```

- 원소의 개수가 n일 때, 평균적으로 O(N^2)의 시간복잡도를 가지고 최선의 경우에는 O(N)의 시간복잡도를 가진다.

## 버블 정렬

    - 인접한 두 원소를 비교, 자리를 교환하는 방식
    - 끝(가장 큰 값)에서부터 채워짐

![bubble_sort](./img/bubble_sort.png)

```c
void bubble_sort(int list[],int n){
    int tmp;
    for(int i=n-1 ; i>0; i--){
        for(int j=0; j<i; j++)
            if(list[j] > list[j+1]) 
                swap(list[j], list[j+1])    //앞뒤를 비교한 후 스왑
    }
}
```

- 원소의 개수가 n일 때, 최대 n(n-1)/2번 정렬