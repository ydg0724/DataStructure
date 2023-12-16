# 그래프 (Graph)

그래프는 객체 사이의 연결 관계를 표현할 수 있는 자료구조이다.

그래프는 정점(vertex)와 간선(edge)들의 유한 집합이라 할 수있다.

```
G = (V,E)
```
V(G)는 그래프 G의 정점들의 집합을, E(G)는 그래프 G의 간선들의 집합을 의미한다.
![graph](./img/graph.png)

- 정점(vertex), 노드(node) : 여러 가지 특성을 가질 수 있는 객체
- 간선(edge), 링크(link) : 정점들 간의 관계
- 무방향 그래프(undirected graph) : 간선의 방향이 없는 그래프 (A,B) = (B,A)
- 방향 그래프(directed graph) : 간선의 방향이 유의미한 그래프 <A,B> != <B,A>
- 가중치 그래프(weighted graph) : 간선에 비용이나 가중치가 할당된 그래프
- 부분 그래프(subgraph) : 어떤 그래프의 정점의 일부와 간선의 일부로 이루어진 그래프
- 경로(path) : 두 정점을 잇는 간선의 열
- 루프(loop) : 한 정점에서 출발하여 자신으로 연결하는 간선
- 사이클(cycle) : 시작점과 끝점이 같은 경로
- 연결 그래프(connected graph) : 모든 정점쌍에 대하여 항상 경로가 존재하는 그래프
- 완전 그래프(complete graph) : 모든 정점이 서로 연결되어 있는 그래프
    - 무방향 그래프의 정점 수가 n이라고 하면 간선의 수는 n(n-1)/2가 된다.

## 그래프 추상 자료형
```
객체 : 정점의 집합과 간선의 집합
연산 : 
    create_graph() ::= 그래프를 생성한다.
    init(g) ::= 그래프 g를 초기화한다.
    insert_vertex(g,v) ::= 그래프 g에 정점 v를 삽입한다.2
    insert_edge(g,u,v) ::= 그래프 g에 간선 (u,v)를 삽입한다.
    delete_vertex(g,v) ::= 그래프 g에 정점 v를 삭제한다.
    delete_edge(g,u,v) ::= 그래프 g에 간선 (u,v)를 삭제한다.
    is_empty(g) ::= 그래프 g가 공백상태인지 확인한다.
    adjacent(v) ::= 정점 v에 인접한 정점들의 리스트를 반환한다.
    destroy_graph(g) ::= 그래프 g를 제거한다.
```

그래프의 표현 방법에는 2가지가 있다.
- 인접 행렬(adjacentcy matrix) : 2차원 배열을 사용한 그래프
- 인접 리스트(adjacency list) : 연결 리스트를 사용한 그래프
## 인접 행렬
adj[i][j] : 노드 i에서 j로 가는 간선이 있으면 1, 없으면 0. cf) 가중치가 있는 그래프라면 1대신 가중치 값을 넣어준다.

- 무방향 그래프
    - 대각 성분을 기준으로 대칭인 성질을 갖게된다.
 ![undirected graph](./img/undirected%20graph.png)

 - 방향 그래프
 ![directed graph](./img/directed%20graph.png)

 장점 : 구현이 쉬우며, 노드 i와 j가 연결되어있는지 확인할 때 adj[i][j]가 0인지 1인지만 확인하면 되므로 시간복잡도가 O(1)이 된다.

 단점 : 노드 i의 차수를 알기 위해서는 adj[i][1]부터 adj[i][n]까지 방문해야하므로 시간복잡도가 O(n)이 되고 모든 간선의 수를 알기 위해서는 행렬 전체를 조사해야하므로 O(n^2)의 시간복잡도가 필요하다

 ## 인접 리스트

![adjacency list](./img/adjacency%20list.png)


