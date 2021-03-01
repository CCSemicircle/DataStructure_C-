#include"Comp.h"
#include"Swap.h"

// 实现希尔排序中调用的特殊插入排序
template<typename E>
void inssort2(E A[], int n, int incr,int cnt[]) {
	for (int i = incr; i < n; i += incr)
		for (int j = i; (j >= incr) && (prior(A[j], A[j - incr]) && (++cnt[0])); j -= incr) {
			swap(A, j, j - incr);
			cnt[1]++;
		}
}

// 实现希尔排序
template<typename E>
void shellsort(E A[], int n, int cnt[]) {
	for (int i = n / 2; i > 2; i /= 2)
		for (int j = 0; j < i; j++)
			inssort2<E>(&A[j], n - j, i, cnt);
	inssort2<E>(A, n, 1, cnt);
}