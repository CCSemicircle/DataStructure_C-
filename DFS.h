#pragma once
#include"Graphm.h"

void PreVisit(Graphm* G, int v) {
	// �ʵ�Ԥ�������ɲ���
}

void PostVisit(Graphm* G, int v) {
	printf("%d\t", v);				// ��ӡ�������
}

// ������������㷨
void DFS(Graphm* G, int v) {
	PreVisit(G, v);				// ִ���ʵ�����
	G->setMark(v, VISITED);		// �������v������
	for (int w = G->first(v); w < G->n(); w = G->next(v, w))				// ���������������һ��·���������ܶ�Ķ���
		if (G->getMark(w) == UNVISITED)
			DFS(G, w);
	PostVisit(G, v);			// ִ���ʵ�����
}