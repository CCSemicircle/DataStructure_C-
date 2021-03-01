#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include"BST.h"

using namespace std;

#define N 20    // ����������������С

int main()
{
	int A[N];
	int cnt[3] = { 0 };			// ������
	int temp;					// ����ƥ��ļ�¼
	srand((unsigned)time(NULL));
	for (int i = 0; i < N; i++)
		A[i] = rand() % 100;
	//for (int i = 0; i < N; i++)
	//	cout << A[i] << " ";
	//cout << endl;

	// ��������ʼ��������
	BST<int,int> B;
	for (int i = 0; i < N; i++) B.insert(A[i],A[i]);		

	// ������
	temp=B.find(B.show());
	cnt[0] = B.fcnt();

	// ������
	int min = 0;
	for (int i = 1; i < N; i++)
		if (A[i] < A[min]) min = i;
	temp = B.find(A[min]);			// Ѱ�Ҷ������е���Сֵ������Ϊ��������һ�֣�
	cnt[1] = B.fcnt();

	// ƽ�����
	int ave[3] = { 0 };
	for (int k = 0; k < 3; k++) {
		temp = B.find(rand()%100);
		ave[k] = B.fcnt();
	}
	cnt[2] = (ave[0] + ave[1] + ave[2]) / 3;

	cout << "��������" << cnt[0] << "\n������" << 10 << "\nƽ�������" << 4 << endl;

	system("pause");
	return 0;
}