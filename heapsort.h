#include"heap.h"

// 实现堆排序
template<typename E>
void heapsort(E A[], int n,int cnt[]) {
	E maxval;
	heap<E> H(A, n, n);			// 创建堆
	for (int i = 0; i < n; i++) {
		maxval = H.removefirst();		// 取最大堆的根结点放置在数组末尾
		A[n-i-1] = maxval;
		cnt[0] = H.ccnt();
		cnt[1] = H.excntt();
	}
}
