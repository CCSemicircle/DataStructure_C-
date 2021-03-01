#include"Comp.h"
#include"Swap.h"

// ʵ�ֻ�������
template<typename E>
void radix(E A[], E B[], int n, int k, int r, int C[],int cnt[]) {
	int j;
	for (int i = 0, rtoi = 1; i < k; i++, rtoi *= r) {			// ѭ������¼������䵽������
		for (j = 0; j < r; j++) C[j] = 0;				// ��ʼ��C����
		for (j = 0; j < n; j++) C[(A[j] / rtoi) % r]++;	// ����Ҫ�ŵ�ÿ����������ļ�¼��
		for (j = 1; j < r; j++) C[j] = C[j - 1] + C[j];			// ��ÿ��������B�а������еļ�¼������ռ�
		for (j = n - 1; j >= 0; j--) {
			B[--C[(A[j] / rtoi) % r]] = A[j];	//	�Ѽ�¼�����ӷ��䵽B��
			cnt[1]++;
		}
		for (j = 0; j < n; j++) {
			A[j] = B[j];				// ���Ѿ��ź��������Ż�A����
			cnt[1]++;
		}
	}
}
