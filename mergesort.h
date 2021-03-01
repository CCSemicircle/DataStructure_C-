#include"inssort.h"

//// �鲢�����׼ʵ��
//template<typename E>
//void mergesort(E A[], E temp[], int left, int right) {
//	if (left == right) return;
//	int mid = (left + right) / 2;
//	mergesort<E>(A, temp, left, mid);
//	mergesort<E>(A, temp, mid + 1, right);
//	for (int i = left; i <= right; i++)
//		temp[i] = A[i];					// �������飬�ݴ����������
//	int i1 = left;
//	int i2 = mid + 1;
//	for (int curr = left; curr <= right; cur++) {				// �Ѹ��������е�����Ԫ������Ż�ԭ����
//		if (i1 == mid + 1) A[curr] = temp[i2++];				// �����λ���飨i1���֣����ֱ꣬���ø�λ������и�ֵ
//		else if (i2 > right) A[curr] = temp[i1++];				// �����λ���飨i2���֣����ֱ꣬���õ�λ������и�ֵ
//		else if (prior(temp[il], temp[i2])&& (++cnt[0])) A[curr] = temp[i1++];	// ��������£��Ƚ���������δ�������е���ǰ��Ԫ�أ�����С��¼�ŵ����������
//		else A[curr] = temp[i2++];
//	}
//}

#define THRESHOLD 4  // ������ֵ

// �鲢�����Ż�ʵ��
template<typename E>
void mergesort(E A[], E temp[], int left, int right, int cnt[]) {
	if ((right - left) <= THRESHOLD) {					// THRESHOLD��һ����ֵ����ÿ������Ԫ�ظ���С����ֵʱ���ò����������С���е�����Ч��
		inssort<E>(&A[left], right - left + 1, cnt);
		return;
	}
	int i, j, k, mid = (left + right) / 2;
	mergesort<E>(A, temp, left, mid, cnt);
	mergesort<E>(A, temp, mid + 1, right, cnt);
	for (i = mid; i >= left; i--) temp[i] = A[i];					// ��δ��������ǰ�벿��˳���ŵ�����������
	for (j = 1; j < right - mid; j++) temp[right - j + 1] = A[j + mid];	// ��δ���������벿�������ŵ�����������
	for (i = left, j = right, k = left; k <= right; k++)				// �������������м��������ֵ
		if (prior(temp[i], temp[j]) && (++cnt[0])) A[k] = temp[i++];
		else A[k] = temp[j--];
}

