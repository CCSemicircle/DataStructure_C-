#include"BinNode.h"

// 二叉检索树结点类
template<typename Key, typename E> 
class BSTNode : public BinNode<E> {
private:
	Key k;			// Key值
	E it;			// value值
	BSTNode* lc;	// 左结点指针
	BSTNode* rc;	// 右结点指针

public:
	// 定义两个构造函数
	BSTNode() { lc = rc = nullptr; }
	BSTNode(Key K, E e, BSTNode* l=nullptr,BSTNode* r=nullptr) 
	{
		k = k;
		it = e;
		lc = l;
		rc = r;
	}

	~BSTNode(){}				// 析构函数

	// 设置或返回结点的Key和value值
	E& element() { return it; }
	void setElement(const E& e) { it = e; }
	Key& key() { return k; }
	void setKey(const Key& K) { k = K; }

	// 设置或返回子结点
	inline BSTNode* left() const { return lc; }
	void setLeft(BinNode<E>* b) { lc = (BSTNode*)b; }
	inline BSTNode* right() const { return rc; }
	void setRight(BinNode<E>* b) { rc = (BSTNode*)b; }

	// 判断是否为叶结点
	bool isleaf() { return(lc == nullptr) && (rc == nullptr); }
};