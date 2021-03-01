#pragma once
#include"Graphm.h"

void PreVisit(Graphm* G, int v) {
	// 适当预操作，可补充
}

void PostVisit(Graphm* G, int v) {
	printf("%d\t", v);				// 打印遍历结果
}

// 深度优先搜索算法
void DFS(Graphm* G, int v) {
	PreVisit(G, v);				// 执行适当操作
	G->setMark(v, VISITED);		// 设置起点v被访问
	for (int w = G->first(v); w < G->n(); w = G->next(v, w))				// 深度优先搜索：沿一条路遍历尽可能多的顶点
		if (G->getMark(w) == UNVISITED)
			DFS(G, w);
	PostVisit(G, v);			// 执行适当操作
}