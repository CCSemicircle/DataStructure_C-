#include<iostream>
#include<string>
#include<cstdlib>
#include"radix.h"

using namespace std;

#define N 20    // ��������Ԫ�ظ���

int main()
{
	int cnt1[2] = { 0,0 }, cnt2[2] = { 0,0 }, cnt3[2] = { 0,0 };							// ��������,cnt[0]Ϊ�Ƚϴ�����cnt[1]Ϊ��������
	int temp[N] = { 0 };		// �ݴ����飨�������飩
	int C[N];				// �����м�ʱ��

	// ������
	int BEST[N];
	for (int i = 0; i < N; i++) BEST[i] = i;
	radix(BEST,temp, N,2,10,C,cnt1);
	cout << "��������\n" << "�Ƚϴ�����" << cnt1[0] << "\n"<< "����������" << cnt1[1] << "\n\n";

	// ������
	int WORST[N];
	for (int i = 0; i < N; i++) WORST[i] = N-i;
	radix(WORST,temp, N,2, 10, C,cnt2);
	cout << "��������\n" << "�Ƚϴ�����" << cnt2[0] << "\n" << "����������" << cnt2[1] << "\n\n";

	// ƽ�����
	int ave[3][2] = {0};			// ��������������ƽ��ֵ���ݴ�����
	int AVERAGE[N];
	for (int k = 0; k < 3; k++) {
		for (int i = 0; i < N; i++)
			AVERAGE[i] = rand() % 100;
		radix(AVERAGE,temp, N,2, 10,C,ave[k]);
	}
	cnt3[0] = (ave[0][0] + ave[1][0] + ave[2][0]) / 3;			// ��������������ƽ��ֵ
	cnt3[1] = (ave[0][1] + ave[1][1] + ave[2][1]) / 3;
	cout << "ƽ�������\n" << "�Ƚϴ�����" << cnt3[0] << "\n" << "����������" << cnt3[1] << "\n\n";

	system("pause");
	return 0;
}