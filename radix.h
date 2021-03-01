#include"Comp.h"
#include"Swap.h"

// 实现基数排序
template<typename E>
void radix(E A[], E B[], int n, int k, int r, int C[],int cnt[]) {
	int j;
	for (int i = 0, rtoi = 1; i < k; i++, rtoi *= r) {			// 循环将记录按序分配到盒子里
		for (j = 0; j < r; j++) C[j] = 0;				// 初始化C数组
		for (j = 0; j < n; j++) C[(A[j] / rtoi) % r]++;	// 计算要放到每个盒子里面的记录数
		for (j = 1; j < r; j++) C[j] = C[j - 1] + C[j];			// 给每个盒子在B中按盒子中的记录数分配空间
		for (j = n - 1; j >= 0; j--) {
			B[--C[(A[j] / rtoi) % r]] = A[j];	//	把记录按盒子分配到B中
			cnt[1]++;
		}
		for (j = 0; j < n; j++) {
			A[j] = B[j];				// 把已经排好序的数组放回A数组
			cnt[1]++;
		}
	}
}
