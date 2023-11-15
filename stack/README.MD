#Stack

    스택은 객체와 그 객체가 저장되는 순서를 기억하는 방법에 대한 추상 자료형이다.

    - 스택의 맨 윗부분을 top 아랫부분을 bottom이라 한다.
    - 데이터를 삽입하는 것을 push 제거하는 것을 pop 읽는 것을 peek라고 한다.
    - 스택의 입출력은 맨 위에서만 일어난다.
    - 이러한 입출력 형태를 후입선출(LIFO : Last-In First-Out)라고 한다.

#Stack의 추상 자료형

    - 객체 : 0개 이상의 원소를 가지는 유한 선형 리스트
    - 함수
        - 'create(size)' ::= 최대 크기가 size인 공백 스택을 생성한다.
        - 'is_full(s)' ::=
            if(스택의 원소수 == size) return TRUE;
            else return FALSE
        - 'is_empty(s)' ::=
            if(스택의 원소수 == 0) return TRUE;
            else return FALSE;
        - 'push(s, item)' ::=
            if( is_full(s) ) return ERROR_STACKFULL;
            else 스택의 맨 위에 item을 추가한다.
        - 'pop(s, item)' ::=
            if( is_empty(s) ) return ERROR_STACKEMPTY;
            else 스택의 맨 위의 원소를 제거해서 반환한다.
        - 'peek(s)' ::=
            if( is_empty(s) ) return ERROR_STACKEMPTY;
            else 스택의 맨 위의 원소를 제거하지 않고 반환한다.

#Stack 구현
    - [Stack.c](stack.c)

#Stack 활용
    - [괄호 검사](check_parenthesis.c)
    - [후위 표기법 계산](postfix.c)
    - [미로 찾기](maze.c)
