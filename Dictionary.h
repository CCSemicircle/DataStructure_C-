// �ֵ�ADT
template<typename Key,typename E>
class Dictionary {
private:
	void operator =(const Dictionary&){}
	Dictionary(const Dictionary&){}

public:
	Dictionary(){}				// ���캯��
	virtual ~Dictionary(){}		// ��������

	// ��ʼ���ֵ�	virtual void clear() = 0;

	// �����¼
	// k: keyֵ
	// e: valueֵ
	virtual void insert(const Key& k, const E& e) = 0;

	// ɾ��������ָ���ļ�¼
	// k: ��ɾ����¼��keyֵ
	// ɾ��������ƥ��keyֵ�ĵ�һ����¼�����ȫ��ƥ���򷵻�NULL
	virtual E remove(const Key& k) = 0;

	// ɾ����������һ��¼�����û�м�¼�򷵻�NULL
	virtual E removeAny() = 0;

	// ����ƥ��keyֵ�ĵ�һ����¼�����ȫ��ƥ���򷵻�NULL
	virtual E find(const Key& k) = 0;
	// �����ֵ䳤��
	virtual int size() = 0;
};
