#include"Graph.h"
#include"Assert.h"

#define UNVISITED 0			// 顶点未被访问置0
#define VISITED 1			// 顶点已被访问置1

// 图的相邻矩阵实现
class Graphm :public Graph{
private:
	int numVertex, numEdge;				// 顶点和边的数目
	int** martrix;						// 边矩阵
	int* mark;							// 用来存储图中的顶点是否被访问

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
			mark[i] = UNVISITED;						// 初始化mark数组
		martrix = (int**)new int*[numVertex];
		for (i = 0; i < numVertex; i++)
			for (int j = 0; j < numVertex; j++)
				martrix[i][j] = 0;							// 初始化边矩阵，在不存在对应边时设置为0
	}

	const int n() { return numVertex; }
	const int e() { return numEdge; }

	// 返回与顶点v的关联的第一个顶点（相邻顶点表按照顶点号排序）
	int first(int v) {
		for (int i = 0; i < numVertex; i++)
			if (martrix[v][i] != 0) return i;			
		return numVertex;
	}

	// 返回与顶点v的关联的边列表中在顶点w之后与v相关联的下一条边所对应的顶点标号（相邻顶点表按照顶点号排序） 
	int next(int v, int w) {
		for (int i = w + 1; i < numVertex; i++)
			if (martrix[v][i] != 0)
				return i;
		return numVertex;
	}

	// 给以v1，v2为顶点的边赋权值
	void setEdge(int v1, int v2, int wt) {
		Assert(wt > 0, "Illegal weight value");
		if (martrix[v1][v2] == 0) numEdge++;
		martrix[v1][v2] = wt;
	}

	// 删除以v1,v2为顶点的一条边
	void delEdge(int v1, int v2) {
		if (martrix[v1][v2] != 0) numEdge--;
		martrix[v1][v2] = 0;				// 删除边即为置为0
	}

	// 判断以i和j为顶点的一条边是否存在
	bool isEdge(int i,int j)
	{
		return martrix[i][j] != 0;
	}

	// 返回边的权重
	int weight(int v1, int v2) { return martrix[v1][v2]; }

	// 获取顶点v的mark数组，或者给顶点v的mark数组赋值
	int getMark(int v) { return mark[v]; }
	void setMark(int v, int val) { mark[v] = val; }
};
