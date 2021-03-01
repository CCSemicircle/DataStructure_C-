#include"Comp.h"
#include"Swap.h"

// Ѱ����ֵ����ʵ��
template<typename E>
inline int findpivot(E A[], int i, int j) {
	return (i + j) / 2;
}

// �������򻮷ֺ���ʵ�֣���
template<typename E>
inline int partition(E A[], int l, int r, E& pivot, int cnt[]) {
	do {
		while (prior(A[++l], pivot));
		while ((l < r) && prior(pivot, A[--r]) && (++cnt[0]))    // l < r����ֹrС��pivotindex֮���������Խ�磩
		{
			swap(A, l, r);
			cnt[1]++;
		}
	} while (l < r);
	return l;				// ���ػ��ֵĻ��ַֽ��
}


// ʵ�ֿ�������
template<typename E>
void qsort(E A[], int i, int j, int cnt[]) {
	if (j <= i) return;
	int pivotindex = findpivot(A, i, j);   // Ѱ����ֵ
	swap(A, pivotindex, j);					// ����ֵ����ĩβ
	cnt[1]++;
	int k = partition<E>(A, i - 1, j, A[j], cnt);		// A[j]Ϊѡ������ֵ
	swap(A, k, j);									// ����ֵ��ĩβ�������ַֽ��
	cnt[1]++;
	qsort<E>(A, i, k - 1,cnt);					
	qsort<E>(A, k + 1, j,cnt);
}
