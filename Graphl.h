#include"Graph.h"
#include"AList.h"
#include"Edge.h"

#define UNVISITED 0			// ����δ��������0
#define VISITED 1			// �����ѱ�������1

// ͼ���ڽӱ�ʵ��
class Graphl {
private:
	AList<Edge>** vertex;			// �ڽӱ�ʵ�ֵ���Ҫ���ݽṹΪһ������ÿ��������һ������
	int numVertex, numEdge;
	int *mark;						// �����洢ͼ�еĶ����Ƿ񱻷���

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
		for (i = 0; i < numVertex; i++) mark[i] = UNVISITED;		// ��ʼ����������ڱ�����
		vertex = (AList<Edge>**) new AList<Edge>*[numVertex];		// ��ͼ�ṹ������������ΪEdge������Ϊ��������
		for(i=0;i<numVertex;i++)
			vertex[i]=new AList<Edge>();				// ���������ÿһ��Ԫ��Ϊ����
	}

	const int n() { return numVertex; }
	const int e() { return numEdge; }

	// �����붥��v�Ĺ����ĵ�һ�����㣨���ڶ�����ն��������
	int first(int v) {
		if (vertex[v]->length() == 0)			// ���Ԫ��������ĳ���Ϊ0����Ϊ�������㣬���ض������
			return numVertex;
		vertex[v]->moveToStart();
		Edge it = vertex[v]->getValue();
		return it.vertex();
	}

	// �����붥��v�Ĺ����ı��б����ڶ���w֮����v���������һ��������Ӧ�Ķ����ţ����ڶ�����ն�������� 
	int next(int v, int w) {
		Edge it;
		if (isEdge(v, w)) {
			if ((vertex[v]->currPos() + 1) < vertex[v]->length()) {
				vertex[v]->next();
				it = vertex[v]->getValue();
				return it.vertex();
			}
		}
		return n();							// �������w֮�󲻴�����һ�����㣬�򷵻ض�������
	}

	// ����i��jΪ����ı߸�Ȩֵ
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
				if (temp.vertex() > j) break;			// ��i��j������ʱ������һ����j������i�����Ķ��㸳ֵ
			}
			vertex[i]->insert(currEdge);
		}
	}

	// ɾ������i��j֮��ı�
	void delEdge(int i, int j) {
		if (isEdge(i, j)) {
			vertex[i]->remove();
			numEdge--;
		}
	}

	// �ж���i��jΪ�����һ�����Ƿ���� 
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
	
	// ���رߵ�Ȩ�� 
	int weight(int i, int j) {
		Edge curr;
		if (isEdge(i, j)) {							// ��������һ��ָ�룬���ж�i��j֮���Ƿ���ڱ�ʱ����ָ�����Ƶ�ָ�򶥵�j��λ�ã�����ǰλ��Ϊj��
			curr = vertex[i]->getValue();
			return curr.weight();
		}
		else return 0;
	}
	
	// ��ȡ����v��mark���飬���߸�����v��mark���鸳ֵ
	int getMark(int v) { return mark[v]; }
	void setMark(int v, int val) { mark[v] = val; }
};
