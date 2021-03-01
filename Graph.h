// Graph ADT
// �ٶ�ͼ�ж�����Ŀ��һ��ʼ���Ѿ�ȷ��
class Graph {
private:
	void operator=(const Graph&){}		// ��������
	Graph(const Graph&){}		// �������ƹ��캯��

public:
	Graph() {}				// ���幹�캯��
	virtual ~Graph(){}		// ������������

	// ��ʼ������n�������ͼ
	virtual void Init(int n) = 0;

	// ���ض���ͱߵ���Ŀ
	virtual const int n() = 0;
	virtual const int e() = 0;

	// �����붥��v�Ĺ����ĵ�һ�����㣨���ڶ�����ն��������
	virtual int first(int v) = 0;

	// �����붥��v�Ĺ����ı��б����ڶ���w֮����v���������һ��������Ӧ�Ķ����ţ����ڶ�����ն��������
	virtual int next(int v, int w) = 0;

	// ����v1��v2Ϊ����ı߸�Ȩֵ
	virtual void setEdge(int v1, int v2, int weight) = 0;

	// ɾ����v1,v2Ϊ�����һ����
	virtual void delEdge(int v1, int v2) = 0;

	// �ж���i��jΪ�����һ�����Ƿ����
	virtual bool isEdge(int i, int j) = 0;

	// ���رߵ�Ȩ��
	virtual int weight(int v1, int v2) = 0;

	// ��ȡ����v��mark���飬���߸�����v��mark���鸳ֵ
	virtual int getMark(int v) = 0;
	virtual void setMark(int v, int val) = 0;
};
