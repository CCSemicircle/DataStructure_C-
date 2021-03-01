// Graph ADT
// 假定图中顶点数目在一开始就已经确定
class Graph {
private:
	void operator=(const Graph&){}		// 保护工作
	Graph(const Graph&){}		// 保护复制构造函数

public:
	Graph() {}				// 定义构造函数
	virtual ~Graph(){}		// 基本析构函数

	// 初始化具有n个顶点的图
	virtual void Init(int n) = 0;

	// 返回顶点和边的数目
	virtual const int n() = 0;
	virtual const int e() = 0;

	// 返回与顶点v的关联的第一个顶点（相邻顶点表按照顶点号排序）
	virtual int first(int v) = 0;

	// 返回与顶点v的关联的边列表中在顶点w之后与v相关联的下一条边所对应的顶点标号（相邻顶点表按照顶点号排序）
	virtual int next(int v, int w) = 0;

	// 给以v1，v2为顶点的边赋权值
	virtual void setEdge(int v1, int v2, int weight) = 0;

	// 删除以v1,v2为顶点的一条边
	virtual void delEdge(int v1, int v2) = 0;

	// 判断以i和j为顶点的一条边是否存在
	virtual bool isEdge(int i, int j) = 0;

	// 返回边的权重
	virtual int weight(int v1, int v2) = 0;

	// 获取顶点v的mark数组，或者给顶点v的mark数组赋值
	virtual int getMark(int v) = 0;
	virtual void setMark(int v, int val) = 0;
};
