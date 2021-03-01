#include"Graphm.h"
#include"AQueue.h"

void PreVisit(Graphm* G, int v) {
	printf("%d\t", v);				// ��ӡ�������
}

// ������������㷨
void BFS(Graphm* G, int start, AQueue<int>* Q) {
	int v, w;
	Q->enqueue(start);					// ����ʼ��Ž�����
	G->setMark(start, VISITED);
	while (Q->length() != 0) {
		v = Q->dequeue();
		PreVisit(G, v);				// ִ���ʵ�����
		for(w = G->first(v); w < G->n(); w = G->next(v, w))				// �����������������ĳ��������������ڶ���֮���ټ�������
			if (G->getMark(w) == UNVISITED) {
				G->setMark(w, VISITED);
				Q->enqueue(w);
			}
	}
}