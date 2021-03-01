#include"BinNode.h"

// ��������������
template<typename Key, typename E> 
class BSTNode : public BinNode<E> {
private:
	Key k;			// Keyֵ
	E it;			// valueֵ
	BSTNode* lc;	// ����ָ��
	BSTNode* rc;	// �ҽ��ָ��

public:
	// �����������캯��
	BSTNode() { lc = rc = nullptr; }
	BSTNode(Key K, E e, BSTNode* l=nullptr,BSTNode* r=nullptr) 
	{
		k = k;
		it = e;
		lc = l;
		rc = r;
	}

	~BSTNode(){}				// ��������

	// ���û򷵻ؽ���Key��valueֵ
	E& element() { return it; }
	void setElement(const E& e) { it = e; }
	Key& key() { return k; }
	void setKey(const Key& K) { k = K; }

	// ���û򷵻��ӽ��
	inline BSTNode* left() const { return lc; }
	void setLeft(BinNode<E>* b) { lc = (BSTNode*)b; }
	inline BSTNode* right() const { return rc; }
	void setRight(BinNode<E>* b) { rc = (BSTNode*)b; }

	// �ж��Ƿ�ΪҶ���
	bool isleaf() { return(lc == nullptr) && (rc == nullptr); }
};