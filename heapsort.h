#include"heap.h"

// ʵ�ֶ�����
template<typename E>
void heapsort(E A[], int n,int cnt[]) {
	E maxval;
	heap<E> H(A, n, n);			// ������
	for (int i = 0; i < n; i++) {
		maxval = H.removefirst();		// ȡ���ѵĸ�������������ĩβ
		A[n-i-1] = maxval;
		cnt[0] = H.ccnt();
		cnt[1] = H.excntt();
	}
}
