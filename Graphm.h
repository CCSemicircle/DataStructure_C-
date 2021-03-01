#include"Graph.h"
#include"Assert.h"

#define UNVISITED 0			// ����δ��������0
#define VISITED 1			// �����ѱ�������1

// ͼ�����ھ���ʵ��
class Graphm :public Graph{
private:
	int numVertex, numEdge;				// ����ͱߵ���Ŀ
	int** martrix;						// �߾���
	int* mark;							// �����洢ͼ�еĶ����Ƿ񱻷���

public:
	Graphm(int numVert) 
	{
		Init(numVert);
	}

	~Graphm() {
		delete[] mark;
		for (int i = 0; i < numVertex; i++)
			delete[] martrix[i];
		delete[] martrix;
	}

	void Init(int n) {
		int i;
		numVertex = n;
		numEdge = n;
		mark = new int[n];
		for (i = 0; i < numVertex; i++)
			mark[i] = UNVISITED;						// ��ʼ��mark����
		martrix = (int**)new int*[numVertex];
		for (i = 0; i < numVertex; i++)
			for (int j = 0; j < numVertex; j++)
				martrix[i][j] = 0;							// ��ʼ���߾����ڲ����ڶ�Ӧ��ʱ����Ϊ0
	}

	const int n() { return numVertex; }
	const int e() { return numEdge; }

	// �����붥��v�Ĺ����ĵ�һ�����㣨���ڶ�����ն��������
	int first(int v) {
		for (int i = 0; i < numVertex; i++)
			if (martrix[v][i] != 0) return i;			
		return numVertex;
	}

	// �����붥��v�Ĺ����ı��б����ڶ���w֮����v���������һ��������Ӧ�Ķ����ţ����ڶ�����ն�������� 
	int next(int v, int w) {
		for (int i = w + 1; i < numVertex; i++)
			if (martrix[v][i] != 0)
				return i;
		return numVertex;
	}

	// ����v1��v2Ϊ����ı߸�Ȩֵ
	void setEdge(int v1, int v2, int wt) {
		Assert(wt > 0, "Illegal weight value");
		if (martrix[v1][v2] == 0) numEdge++;
		martrix[v1][v2] = wt;
	}

	// ɾ����v1,v2Ϊ�����һ����
	void delEdge(int v1, int v2) {
		if (martrix[v1][v2] != 0) numEdge--;
		martrix[v1][v2] = 0;				// ɾ���߼�Ϊ��Ϊ0
	}

	// �ж���i��jΪ�����һ�����Ƿ����
	bool isEdge(int i,int j)
	{
		return martrix[i][j] != 0;
	}

	// ���رߵ�Ȩ��
	int weight(int v1, int v2) { return martrix[v1][v2]; }

	// ��ȡ����v��mark���飬���߸�����v��mark���鸳ֵ
	int getMark(int v) { return mark[v]; }
	void setMark(int v, int val) { mark[v] = val; }
};
