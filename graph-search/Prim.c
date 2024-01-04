#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define False 0
#define MAX_VERTICES 100
#define INF 1000

typedef struct GraghType {
	int n;	//정점의 개수
	int weight[MAX_VERTICES][MAX_VERTICES];
}GraphType;

int selected[MAX_VERTICES];
int distance[MAX_VERTICES];

//최소 dist[v] 값을 갖는 정점 반환
int get_min_vertex(int n) {
	int v, i;
	for (int i = 0; i < n; i++) {
		if (!selected) {	//첫 번째 정점
			v = i;
			break;
		}
		for (i = 0; i < n; i++)	
			if (!selected[i] && (distance[i] < distance[v])) v = i;	//두 번째 정점을 찾은 후 비교
		return v;
	}
}

void prim(GraphType* g, int s) {
	int i, u, v;

	for (u = 0; u < g->n; u++) distance[u] = INF;
	distance[s] = 0;
	for (int i = 0; i < g->n; i++) {
		u = get_min_vertex(g->n);
		selected[u] = TRUE;
		if (distance[u] == INF) return;
		printf("정점 %d 추가\n", u);
		for (v = 0; v < g->n; v++)
			if (g->weight[u][v] != INF)
				if (!selected[v] && g->weight[u][v] < distance[v])
					distance[v] = g->weight[u][v];
	}
}
int main() {
	GraphType g = { 7,{ 0, 29, INF, INF, INF, INF,},
	{ 29, 0, 16, INF, INF, INF,INF} ,
	{ INF, 16, 0, 12, INF, INF,INF} ,
	{ INF, INF, 12, 0, 22, INF,INF} ,
	{ INF, INF, INF, 22, 0, 27,25} ,
	{ 10, INF, INF, INF, 27, 0, INF} ,
	{ INF, 15, INF, 18, 25, INF,0}
	};
	prim(&g, 0);
	return 0;
}