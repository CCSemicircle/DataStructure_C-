#include"Graphm.h"
#include"AQueue.h"

void printout(int v) {
	printf("%d\t", v);			
}

// 基于队列的拓扑排序算法
void Qtopsort(Graphm* G, Queue<int>* Q) {
	int* Count;
	Count = new int[G->n()];
	int v, w;
	for (v = 0; v < G->n(); v++) Count[v] = 0;			// 初始化
	for (v = 0; v < G->n(); v++)
		for (w = G->first(v); w < G->n(); w = G->next(v, w))			// 按顺序逐级遍历所有顶点
			Count[w]++;							// 记录每个顶点的限制数（前面的限制顶点有多少），限制数为0即可作为端点（出度为0的点）
	for (v = 0; v < G->n(); v++)					// 把孤立顶点放入队列
		if (Count[v] == 0)
			Q->enqueue(v);
	while (Q->length() != 0) {
		v = Q->dequeue();
		printout(v);							// 打印排序结果，但是是从最高级开始打印，颠倒顺序之后才为目标拓扑排序
		for (w = G->first(v); w < G->n(); w = G->next(v, w)) {
			Count[w]--;
			if (Count[w] == 0)
				Q->enqueue(w);								// 端点放在队列最后面，最后输出
		}
	}
}


// 递归拓扑排序
void tophelp(Graphm* G, int v) {
	G->setMark(v, VISITED);
	for (int w = G->first(v); w < G->n(); w = G->next(v, w))			// 遍历该顶点的下一级顶点
		if (G->getMark(w) == UNVISITED)
			tophelp(G, w);										// 从最低一级向上递归，遍历每个顶点之间的前后限制
	printout(v);									// 利用递归打印，从最低一级开始打印 
}

void Rtopsort(Graphm* G) {
	int i;
	for (i = 0; i < G->n(); i++)				// 初始化mark数组
		G->setMark(i, UNVISITED);
	for (i = 0; i < G->n(); i++)
		if (G->getMark(i) == UNVISITED)
			tophelp(G, i);
}