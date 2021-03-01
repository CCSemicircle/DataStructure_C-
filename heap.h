#include"Comp.h"
#include"Swap.h"
#include"Assert.h"

// ʵ������
template<typename E>
class heap {
private:
	E* Heap;			// ָ��������ָ��
	int maxsize;		// �ѵ����ռ�
	int n;				// ���е�ǰԪ�ظ���
	int cnt[2];			// ������

	void siftdown(int pos) {					// �������Ѵ�ĳ��Ԫ�ؿ�ʼ�����У�����Сֵ�����
		while (!isLeaf(pos)) {
			int j = leftchild(pos);
			int rc = rightchild(pos);
			if ((rc < n) && !prior(Heap[rc], Heap[j]) && (++cnt[0])) j = rc;	 // ���ϴ�ֵ��index��ֵ��j			
			if (!prior(Heap[pos], Heap[j]) && (++cnt[0])) return;				// ��������ӽ���еĽϴ�ֵ�Ƚ�
			swap(Heap, pos, j);
			cnt[1]++;
			pos = j;
		}
	}

public:
	// ���캯��
	heap(E* h, int num, int max) {
		Heap = h;
		n = num;
		maxsize = max;
		buildHeap();
	}

	int size() const { return n; }	// ���ص�ǰ�ѵĴ�С

	// �ж��Ƿ�ΪҶ�ӽڵ�
	bool isLeaf(int pos) const {
		return (pos >= n / 2) && (pos < n);		// �б����ݣ�������ȫ�����������ԣ�����ÿ���һ���㶼�Ƕ����н�����ӱ������ҽ��������������Ų����洢��������

	}

	int leftchild(int pos) const { return 2 * pos + 1; }		// �������ӽ��

	int rightchild(int pos) const { return 2 * pos + 2; }		// �������ӽ��

	int parent(int pos)const { return (pos - 1) / 2; }			// ���ظ����

	void buildHeap() { for (int i = n / 2 - 1; i >= 0; i--) siftdown(i); }	// ���������е����ѵ��Ų�

	// ����Ԫ��
	void insert(const E& it) {
		Assert(n < maxsize, "Heap is full");
		int curr = n++;
		Heap[curr] = it;
		while ((curr!=0) && !prior(Heap[curr], Heap[parent(curr)]) && (++cnt[0])) {			// ��Ԫ���ƶ������ʵĽ��
			swap(Heap, curr, parent[curr]);
			cnt[1]++;
			curr = parent(curr);
		}
	}

	// �Ƴ������ظ����
	E removefirst() {
		Assert(n > 0, "Heap is empty");
		swap(Heap, 0, --n);
		cnt[1]++;
		if (n != 0) siftdown(0);
		return Heap[n];
	}

	// �Ƴ�������ָ��Ԫ��
	E remove(int pos) {
		Assert((pos >= 0) && (pos < n), "Bad position");
		if (pos == (n - 1)) n--;			// ���ָ���������һ��Ԫ�أ�ֱ�ӽ���ǰԪ�ظ�����һ����
		else {
			swap(Heap, pos, --n);			// ��ָ��index��ֵ������Ԫ�ؽ���
			cnt[1]++;
			while ((pos != 0) && (!prior(Heap[pos], Heap[parent(pos)]))) {
				swap(Heap, pos, parent(pos));			// ���ϴ�ֵ��ǰ��
				cnt[1]++;
				pos = parent(pos);
			}
			if (n != 0) siftdown(pos);					// �������Ѵ�pos��ʼ�����У�����Сֵ�����
		}
		return Heap[n];				// ��ĩβԪ��Ϊָ��index��ֵ
	}

	int ccnt() { return cnt[0]; }			// ���رȽϴ���

	int excntt() { return cnt[1]; }		   // ���ؽ�������
};
