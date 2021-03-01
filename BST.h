#include"BSTNode.h"
#include"Dictionary.h"
#include<iostream>

using namespace std;

// ʵ�ֶ��������
template<typename Key, typename E>
class BST :public Dictionary<Key, E> {
private:
	BSTNode<Key, E>* root;			// �����
	int nodecount;					// ������
	int cnt = 0;				// ���ң��Ƚϣ�������

	// ˽��"helper"����
	void clearhelp(BSTNode<Key, E>* root) {
		if (root == nullptr) return;
		clearhelp(root->left());				// �������������ɾ�����н��
		clearhelp(root->right());
		delete root;
	}

	BSTNode<Key, E>* inserthelp(BSTNode<Key, E>* root, const Key& k, const E& it) {
		if (root == nullptr)  return new BSTNode<Key, E>(k, it, nullptr, nullptr);
		if (k < root->key()) root->setLeft(inserthelp(root->left(), k, it));			 // �Ƚ��С�������ӽڵ㣬�Ƚ���������ӽڵ�
		else root->setRight(inserthelp(root->right(), k, it));
		return root;				// ���ز���Ľ��
	}

	BSTNode<Key, E>* deletemin(BSTNode<Key, E>* rt) {
		if (rt->left() == nullptr)	return  rt->right();			// ��ָ����С����ָ���Ϊָ����С�������ӽ��
		else {
			rt->setLeft(deletemin(rt->left()));
			return rt;
		}
	}

	BSTNode<Key, E>* getmin(BSTNode<Key, E>* rt) {					// �ݹ�������������ҵ�û�����ӽ��Ľ�㣬������С���
		if (rt->left() == nullptr)		return  rt;			
		else return getmin(rt->left());
	}

	BSTNode<Key, E>* removehelp(BSTNode<Key, E>* rt, const Key& k) {
		if (rt == nullptr) return nullptr;				// û��ƥ���keyֵ
		else if (k < rt->key())
			rt->setLeft(removehelp(rt->left(), k));
		else if (k > rt->key())
			rt->setRight(removehelp(rt->right(), k));
		else {												// ��ɾ�����ֻ��һ�����ӽ���ʱָ�������ӽ��
			BSTNode<Key, E>* temp = rt;
			if (rt->left() == nullptr) {
				rt = rt->right();
				delete temp;
			}
			else if (rt->right() == nullptr) {				// ��ɾ�����ֻ��һ�����ӽ���ʱָ�������ӽ��
				rt = rt->left();
				delete temp;
			}
			else {												// ��ɾ������������ӽ��
				BSTNode<Key, E>* temp = getmin(rt->right());
				rt->setElement(temp->element());
				rt->setKey(temp->key());
				rt->setRight(deletemin(rt->right()));
				delete temp;
			}
		}
		return rt;
	}

	E findhelp(BSTNode<Key, E>* root, const Key& k)  {					// �������
		cnt++;
		if (root == nullptr) return NULL;
		if (k < root->key()) return findhelp(root->left(), k);
		else if (k > root->key()) return findhelp(root->right(), k);
		else return root->element();
	}

	void printhelp(BSTNode<Key, E>* root, int level) const {
		if (root == nullptr) return;
		printhelp(root->left(), level + 1);			// ��ӡ������
		for (int i = 0; i < level; i++) cout << " ";		// ���ÿ�����
		cout << root->key() << "\n";						// ��ӡ���keyֵ
		printhelp(root->right(), level + 1);				// ��ӡ������
	}

public:
	BST() { root = nullptr; nodecount = 0; }			// ���캯��
	~BST() { clearhelp(root); }								// ��������

	void clear()	// ��ʼ��
	{
		clearhelp(root); 
		root = nullptr;
		nodecount = 0;
	}

	// ������
	void insert(const Key& k, const E& e) {
		root = inserthelp(root, k, e);
		nodecount++;
	}

    // ɾ�������ص�һ��ƥ��keyֵ�Ľ�㣬ȫ��ƥ���򷵻�NULL
	E remove(const Key& k) {
		E temp = findhelp(root, k);				// �ҵ���һ��ƥ��Ľ��
		if (temp != NULL) {
			root = removehelp(root, k);
			nodecount--;
		}
		return temp;
	}

	// ɾ�������ظ����
	E removeAny() {
		if (root != nullptr) {
			E temp = root->element();
			root = removehelp(root, root->key());
			nodecount--;
			return temp;
		}
		else return NULL;
	}

	// ����ƥ��keyֵ�ĵ�һ����¼�����ȫ��ƥ���򷵻�NULL
	E find(const Key& k) { return findhelp(root, k); }

	// ���ؽ�����
	int size() { return nodecount; }

	// ��ӡ����������ĸ����
	void print() const {
		if (root == nullptr) cout << "The BST is empty" << endl;
		else printhelp(root, 0);
	}

	// ���ظ����
	E show() {
		return root->key();
	}

	// ���ز��ң��Ƚϣ�����,�������Ա��´μ���
	int fcnt() {
		int temp = cnt;
		cnt = 0;
		return temp;
	}

};
