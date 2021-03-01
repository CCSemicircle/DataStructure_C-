#include"BSTNode.h"
#include"Dictionary.h"
#include<iostream>

using namespace std;

// 实现二叉检索树
template<typename Key, typename E>
class BST :public Dictionary<Key, E> {
private:
	BSTNode<Key, E>* root;			// 根结点
	int nodecount;					// 结点个数
	int cnt = 0;				// 查找（比较）计数器

	// 私有"helper"函数
	void clearhelp(BSTNode<Key, E>* root) {
		if (root == nullptr) return;
		clearhelp(root->left());				// 后序遍历，依次删除所有结点
		clearhelp(root->right());
		delete root;
	}

	BSTNode<Key, E>* inserthelp(BSTNode<Key, E>* root, const Key& k, const E& it) {
		if (root == nullptr)  return new BSTNode<Key, E>(k, it, nullptr, nullptr);
		if (k < root->key()) root->setLeft(inserthelp(root->left(), k, it));			 // 比结点小插入左子节点，比结点大插入右子节点
		else root->setRight(inserthelp(root->right(), k, it));
		return root;				// 返回插入的结点
	}

	BSTNode<Key, E>* deletemin(BSTNode<Key, E>* rt) {
		if (rt->left() == nullptr)	return  rt->right();			// 将指向最小结点的指针改为指向最小结点的右子结点
		else {
			rt->setLeft(deletemin(rt->left()));
			return rt;
		}
	}

	BSTNode<Key, E>* getmin(BSTNode<Key, E>* rt) {					// 递归遍历二叉树，找到没有左子结点的结点，就是最小结点
		if (rt->left() == nullptr)		return  rt;			
		else return getmin(rt->left());
	}

	BSTNode<Key, E>* removehelp(BSTNode<Key, E>* rt, const Key& k) {
		if (rt == nullptr) return nullptr;				// 没有匹配的key值
		else if (k < rt->key())
			rt->setLeft(removehelp(rt->left(), k));
		else if (k > rt->key())
			rt->setRight(removehelp(rt->right(), k));
		else {												// 被删除结点只有一个右子结点的时指向其右子结点
			BSTNode<Key, E>* temp = rt;
			if (rt->left() == nullptr) {
				rt = rt->right();
				delete temp;
			}
			else if (rt->right() == nullptr) {				// 被删除结点只有一个左子结点的时指向其左子结点
				rt = rt->left();
				delete temp;
			}
			else {												// 被删除结点有两个子结点
				BSTNode<Key, E>* temp = getmin(rt->right());
				rt->setElement(temp->element());
				rt->setKey(temp->key());
				rt->setRight(deletemin(rt->right()));
				delete temp;
			}
		}
		return rt;
	}

	E findhelp(BSTNode<Key, E>* root, const Key& k)  {					// 二叉检索
		cnt++;
		if (root == nullptr) return NULL;
		if (k < root->key()) return findhelp(root->left(), k);
		else if (k > root->key()) return findhelp(root->right(), k);
		else return root->element();
	}

	void printhelp(BSTNode<Key, E>* root, int level) const {
		if (root == nullptr) return;
		printhelp(root->left(), level + 1);			// 打印左子树
		for (int i = 0; i < level; i++) cout << " ";		// 间隔每个结点
		cout << root->key() << "\n";						// 打印结点key值
		printhelp(root->right(), level + 1);				// 打印右子树
	}

public:
	BST() { root = nullptr; nodecount = 0; }			// 构造函数
	~BST() { clearhelp(root); }								// 析构函数

	void clear()	// 初始树
	{
		clearhelp(root); 
		root = nullptr;
		nodecount = 0;
	}

	// 插入结点
	void insert(const Key& k, const E& e) {
		root = inserthelp(root, k, e);
		nodecount++;
	}

    // 删除并返回第一个匹配key值的结点，全不匹配则返回NULL
	E remove(const Key& k) {
		E temp = findhelp(root, k);				// 找到第一个匹配的结点
		if (temp != NULL) {
			root = removehelp(root, k);
			nodecount--;
		}
		return temp;
	}

	// 删除并返回根结点
	E removeAny() {
		if (root != nullptr) {
			E temp = root->element();
			root = removehelp(root, root->key());
			nodecount--;
			return temp;
		}
		else return NULL;
	}

	// 返回匹配key值的第一条记录，如果全不匹配则返回NULL
	E find(const Key& k) { return findhelp(root, k); }

	// 返回结点个数
	int size() { return nodecount; }

	// 打印二叉检索树的根结点
	void print() const {
		if (root == nullptr) cout << "The BST is empty" << endl;
		else printhelp(root, 0);
	}

	// 返回根结点
	E show() {
		return root->key();
	}

	// 返回查找（比较）次数,并置零以便下次计数
	int fcnt() {
		int temp = cnt;
		cnt = 0;
		return temp;
	}

};
