#include"Graphm.h"
#include"AQueue.h"

void printout(int v) {
	printf("%d\t", v);			
}

// ���ڶ��е����������㷨
void Qtopsort(Graphm* G, Queue<int>* Q) {
	int* Count;
	Count = new int[G->n()];
	int v, w;
	for (v = 0; v < G->n(); v++) Count[v] = 0;			// ��ʼ��
	for (v = 0; v < G->n(); v++)
		for (w = G->first(v); w < G->n(); w = G->next(v, w))			// ��˳���𼶱������ж���
			Count[w]++;							// ��¼ÿ���������������ǰ������ƶ����ж��٣���������Ϊ0������Ϊ�˵㣨����Ϊ0�ĵ㣩
	for (v = 0; v < G->n(); v++)					// �ѹ�������������
		if (Count[v] == 0)
			Q->enqueue(v);
	while (Q->length() != 0) {
		v = Q->dequeue();
		printout(v);							// ��ӡ�������������Ǵ���߼���ʼ��ӡ���ߵ�˳��֮���ΪĿ����������
		for (w = G->first(v); w < G->n(); w = G->next(v, w)) {
			Count[w]--;
			if (Count[w] == 0)
				Q->enqueue(w);								// �˵���ڶ�������棬������
		}
	}
}


// �ݹ���������
void tophelp(Graphm* G, int v) {
	G->setMark(v, VISITED);
	for (int w = G->first(v); w < G->n(); w = G->next(v, w))			// �����ö������һ������
		if (G->getMark(w) == UNVISITED)
			tophelp(G, w);										// �����һ�����ϵݹ飬����ÿ������֮���ǰ������
	printout(v);									// ���õݹ��ӡ�������һ����ʼ��ӡ 
}

void Rtopsort(Graphm* G) {
	int i;
	for (i = 0; i < G->n(); i++)				// ��ʼ��mark����
		G->setMark(i, UNVISITED);
	for (i = 0; i < G->n(); i++)
		if (G->getMark(i) == UNVISITED)
			tophelp(G, i);
}