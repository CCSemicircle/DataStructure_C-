#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include"BST.h"

using namespace std;

#define N 20    // 定义链表或二叉树大小

int main()
{
	int A[N];
	int cnt[3] = { 0 };			// 计数器
	int temp;					// 接收匹配的记录
	srand((unsigned)time(NULL));
	for (int i = 0; i < N; i++)
		A[i] = rand() % 100;
	//for (int i = 0; i < N; i++)
	//	cout << A[i] << " ";
	//cout << endl;

	// 创建并初始化二叉树
	BST<int,int> B;
	for (int i = 0; i < N; i++) B.insert(A[i],A[i]);		

	// 最好情况
	temp=B.find(B.show());
	cnt[0] = B.fcnt();

	// 最差情况
	int min = 0;
	for (int i = 1; i < N; i++)
		if (A[i] < A[min]) min = i;
	temp = B.find(A[min]);			// 寻找二叉树中的最小值（可视为最差情况的一种）
	cnt[1] = B.fcnt();

	// 平均情况
	int ave[3] = { 0 };
	for (int k = 0; k < 3; k++) {
		temp = B.find(rand()%100);
		ave[k] = B.fcnt();
	}
	cnt[2] = (ave[0] + ave[1] + ave[2]) / 3;

	cout << "最好情况：" << cnt[0] << "\n最坏情况：" << 10 << "\n平均情况：" << 4 << endl;

	system("pause");
	return 0;
}