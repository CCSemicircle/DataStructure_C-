#include"Comp.h"
#include"Swap.h"

// 寻找轴值函数实现
template<typename E>
inline int findpivot(E A[], int i, int j) {
	return (i + j) / 2;
}

// 快速排序划分函数实现，将
template<typename E>
inline int partition(E A[], int l, int r, E& pivot, int cnt[]) {
	do {
		while (prior(A[++l], pivot));
		while ((l < r) && prior(pivot, A[--r]) && (++cnt[0]))    // l < r，防止r小于pivotindex之后下溢出（越界）
		{
			swap(A, l, r);
			cnt[1]++;
		}
	} while (l < r);
	return l;				// 返回划分的划分分界点
}


// 实现快速排序
template<typename E>
void qsort(E A[], int i, int j, int cnt[]) {
	if (j <= i) return;
	int pivotindex = findpivot(A, i, j);   // 寻找轴值
	swap(A, pivotindex, j);					// 将轴值放置末尾
	cnt[1]++;
	int k = partition<E>(A, i - 1, j, A[j], cnt);		// A[j]为选定的轴值
	swap(A, k, j);									// 将轴值从末尾换到划分分界点
	cnt[1]++;
	qsort<E>(A, i, k - 1,cnt);					
	qsort<E>(A, k + 1, j,cnt);
}
