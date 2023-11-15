#Queue

    큐는 먼저 들어온 데이터가 먼저 나가는 구조인 추상 자료형이다.

    - 뒤에서 데이터가 추가되고 앞에서 데이터가 하나씩 삭제되는 구조이다.
    - 삽입이 일어나는 곳을 후단(rear)라고 한다.
    - 삭제가 일어나는 곳을 전단(front)라고 한다.
    - 이러한 입출력 형태를 선입선출(FIFO : First-In First-Out)라고 한다.

##Queue의 추상 자료형

    - 객체 : 0개 이상의 요소들로 구성된 선형 리스트
    - 함수
        - 'create(max_size)' ::= 최대 크기가 max_size인 공백큐를 생성한다.
        - 'init(q)' ::= 큐를 초기화한다.
        - 'is_empty(q)' ::=
            if(size==0) return TRUE;
            else return FALSE;
        - 'is_full(q)' ::=
            if(size == max_size) return TRUE;
            else return FALSE;
        - 'enqueue(q, e)' ::=
            if( is_full(q) ) ERROR_QUEUEFULL;
            else q의 끝에 e를 추가한다.
        - 'dequeue(q)' ::=
            if( is_empty(q) ) ::= ERROR_QUEUEEMPTY;
            else q의 맨 앞에 있는 e를 제거하여 반환한다.
        - 'peek(q)' ::=
            if ( is_empty(q) ) ::= ERROR_QUEUEEMPTY;
            else q의 맨 앞에 있는 e를 읽어서 반환한다.

##Queue 구현
[선형큐](LinearQueue.c)

#원형큐(CircleQueue)

    선형큐는 front와 rear의 값이 계속 증가만 한다. 따라서 언제가는 배열의 끝에 도달하게 되고 배열의 앞부분이 비어 있더라도 사용하지 못한다는 단점이 있다.

    이런 문제는 원형큐로 해결할 수 있다. 원형 큐는 큐의 입구와 출구를 연결시킨 형태이다.

    따라서 길이가 N인 큐에서 rear의 위치가 N-1이 되면 다음 rear가 가리키는 위치가 0이 되도록 하면 된다.

    처음은 rear, front를 0으로 시작하고 첫 원소를 1번 주소부터 삽입한다. 그 후 front와 rear는 다음과 같이 설정한다.

    - 'rear <- (rear+1) % n'
    - 'front <- (front+1) % n'

##원형큐 구현
[원형큐](CircleQueue.c)