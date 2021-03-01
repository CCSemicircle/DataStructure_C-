#include"Graphm.h"
#include"AQueue.h"

void PreVisit(Graphm* G, int v) {
	printf("%d\t", v);				// 打印遍历结果
}

// 广度优先搜索算法
void BFS(Graphm* G, int start, AQueue<int>* Q) {
	int v, w;
	Q->enqueue(start);					// 把起始点放进队列
	G->setMark(start, VISITED);
	while (Q->length() != 0) {
		v = Q->dequeue();
		PreVisit(G, v);				// 执行适当操作
		for(w = G->first(v); w < G->n(); w = G->next(v, w))				// 广度优先搜索：遍历某个顶点的所有相邻顶点之后再继续遍历
			if (G->getMark(w) == UNVISITED) {
				G->setMark(w, VISITED);
				Q->enqueue(w);
			}
	}
}