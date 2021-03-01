#include"Graph.h"
#include"AList.h"
#include"Edge.h"

#define UNVISITED 0			// 顶点未被访问置0
#define VISITED 1			// 顶点已被访问置1

// 图的邻接表实现
class Graphl {
private:
	AList<Edge>** vertex;			// 邻接表实现的主要数据结构为一组链表，每个顶点有一个链表
	int numVertex, numEdge;
	int *mark;						// 用来存储图中的顶点是否被访问

public:
	Graphl(int numVert)
	{
		Init(numVert);
	}

	~Graphl() {
		delete[] mark;
		for (int i = 0; i < numVertex; i++)
			delete[] vertex[i];
		delete[] vertex;
	}

	void Init(int n) {
		int i;
		numVertex = n;
		numEdge = 0;
		mark = new int[n];
		for (i = 0; i < numVertex; i++) mark[i] = UNVISITED;		// 初始化顶点的相邻边数组
		vertex = (AList<Edge>**) new AList<Edge>*[numVertex];		// 将图结构化成数据类型为Edge以链表为结点的数组
		for(i=0;i<numVertex;i++)
			vertex[i]=new AList<Edge>();				// 设置数组的每一个元素为链表
	}

	const int n() { return numVertex; }
	const int e() { return numEdge; }

	// 返回与顶点v的关联的第一个顶点（相邻顶点表按照顶点号排序）
	int first(int v) {
		if (vertex[v]->length() == 0)			// 如果元素中链表的长度为0，即为孤立顶点，返回顶点个数
			return numVertex;
		vertex[v]->moveToStart();
		Edge it = vertex[v]->getValue();
		return it.vertex();
	}

	// 返回与顶点v的关联的边列表中在顶点w之后与v相关联的下一条边所对应的顶点标号（相邻顶点表按照顶点号排序） 
	int next(int v, int w) {
		Edge it;
		if (isEdge(v, w)) {
			if ((vertex[v]->currPos() + 1) < vertex[v]->length()) {
				vertex[v]->next();
				it = vertex[v]->getValue();
				return it.vertex();
			}
		}
		return n();							// 如果顶点w之后不存在下一个顶点，则返回顶点总数
	}

	// 给以i，j为顶点的边赋权值
	void setEdge(int i, int j, int weight) {
		Assert(weight > 0, "May not set weight to 0");
		Edge currEdge(j, weight);
		if (isEdge(i, j)) {
			vertex[i]->remove();
			vertex[i]->insert(currEdge);
		}
		else {
			numEdge++;
			for (vertex[i]->moveToStart();
				vertex[i]->currPos() < vertex[i]->length();
				vertex[i]->next()) {
				Edge temp = vertex[i]->getValue();
				if (temp.vertex() > j) break;			// 在i，j不相连时，给第一个比j大且与i相连的顶点赋值
			}
			vertex[i]->insert(currEdge);
		}
	}

	// 删除顶点i，j之间的边
	void delEdge(int i, int j) {
		if (isEdge(i, j)) {
			vertex[i]->remove();
			numEdge--;
		}
	}

	// 判断以i和j为顶点的一条边是否存在 
	bool isEdge(int i, int j) {
		Edge it;
		for (vertex[i]->moveToStart();
			vertex[i]->currPos() < vertex[i]->length();
			vertex[i]->next()) {
			Edge temp = vertex[i]->getValue();
			if (temp.vertex() == j) return true;
		}
		return false;
	}
	
	// 返回边的权重 
	int weight(int i, int j) {
		Edge curr;
		if (isEdge(i, j)) {							// 链表里有一个指针，在判断i，j之间是否存在边时，该指针已移到指向顶点j的位置（即当前位置为j）
			curr = vertex[i]->getValue();
			return curr.weight();
		}
		else return 0;
	}
	
	// 获取顶点v的mark数组，或者给顶点v的mark数组赋值
	int getMark(int v) { return mark[v]; }
	void setMark(int v, int val) { mark[v] = val; }
};
