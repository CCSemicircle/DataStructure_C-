#include"inssort.h"

//// 归并排序标准实现
//template<typename E>
//void mergesort(E A[], E temp[], int left, int right) {
//	if (left == right) return;
//	int mid = (left + right) / 2;
//	mergesort<E>(A, temp, left, mid);
//	mergesort<E>(A, temp, mid + 1, right);
//	for (int i = left; i <= right; i++)
//		temp[i] = A[i];					// 辅助数组，暂存待排序子列
//	int i1 = left;
//	int i2 = mid + 1;
//	for (int curr = left; curr <= right; cur++) {				// 把辅助数组中的子列元素有序放回原数组
//		if (i1 == mid + 1) A[curr] = temp[i2++];				// 如果低位数组（i1部分）用完，直接用高位数组进行赋值
//		else if (i2 > right) A[curr] = temp[i1++];				// 如果高位数组（i2部分）用完，直接用低位数组进行赋值
//		else if (prior(temp[il], temp[i2])&& (++cnt[0])) A[curr] = temp[i1++];	// 正常情况下，比较两个数组未处理序列的最前端元素，将较小记录放到输出数组中
//		else A[curr] = temp[i2++];
//	}
//}

#define THRESHOLD 4  // 定义阈值

// 归并排序优化实现
template<typename E>
void mergesort(E A[], E temp[], int left, int right, int cnt[]) {
	if ((right - left) <= THRESHOLD) {					// THRESHOLD是一个阈值，当每个子列元素个数小于阈值时采用插入排序，提高小子列的排序效率
		inssort<E>(&A[left], right - left + 1, cnt);
		return;
	}
	int i, j, k, mid = (left + right) / 2;
	mergesort<E>(A, temp, left, mid, cnt);
	mergesort<E>(A, temp, mid + 1, right, cnt);
	for (i = mid; i >= left; i--) temp[i] = A[i];					// 将未排序数组前半部分顺序存放到辅助数组中
	for (j = 1; j < right - mid; j++) temp[right - j + 1] = A[j + mid];	// 将未排序数组后半部分逆序存放到辅助数组中
	for (i = left, j = right, k = left; k <= right; k++)				// 从数组两端向中间检索并赋值
		if (prior(temp[i], temp[j]) && (++cnt[0])) A[k] = temp[i++];
		else A[k] = temp[j--];
}

