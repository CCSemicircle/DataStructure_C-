// 二叉树结点类
template<typename E> class BinNode {
public:
	virtual ~BinNode(){}			// 析构函数

	// 返回结点值
	virtual E& element() = 0;

	// 设定结点值
	virtual void setElement(const E&) = 0;

	// 返回左子结点
	virtual BinNode* left() const = 0;

	// 设置左子结点
	virtual void setLeft(BinNode*) = 0;

	// 返回右子结点
	virtual BinNode* right() const = 0;

	// 设置右子结点
	virtual void setRight(BinNode*) = 0;

	// 判断是否为叶结点
	virtual bool isleaf() = 0;
};
