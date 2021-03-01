// 字典ADT
template<typename Key,typename E>
class Dictionary {
private:
	void operator =(const Dictionary&){}
	Dictionary(const Dictionary&){}

public:
	Dictionary(){}				// 构造函数
	virtual ~Dictionary(){}		// 析构函数

	// 初始化字典	virtual void clear() = 0;

	// 插入记录
	// k: key值
	// e: value值
	virtual void insert(const Key& k, const E& e) = 0;

	// 删除并返回指定的记录
	// k: 被删除记录的key值
	// 删除并返回匹配key值的第一个记录，如果全不匹配则返回NULL
	virtual E remove(const Key& k) = 0;

	// 删除并返回任一记录，如果没有记录则返回NULL
	virtual E removeAny() = 0;

	// 返回匹配key值的第一条记录，如果全不匹配则返回NULL
	virtual E find(const Key& k) = 0;
	// 返回字典长度
	virtual int size() = 0;
};
