// �����������
template<typename E> class BinNode {
public:
	virtual ~BinNode(){}			// ��������

	// ���ؽ��ֵ
	virtual E& element() = 0;

	// �趨���ֵ
	virtual void setElement(const E&) = 0;

	// �������ӽ��
	virtual BinNode* left() const = 0;

	// �������ӽ��
	virtual void setLeft(BinNode*) = 0;

	// �������ӽ��
	virtual BinNode* right() const = 0;

	// �������ӽ��
	virtual void setRight(BinNode*) = 0;

	// �ж��Ƿ�ΪҶ���
	virtual bool isleaf() = 0;
};
