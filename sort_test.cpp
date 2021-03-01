#include<iostream>
#include<string>
#include<cstdlib>
#include"radix.h"

using namespace std;

#define N 20    // 测试数组元素个数

int main()
{
	int cnt1[2] = { 0,0 }, cnt2[2] = { 0,0 }, cnt3[2] = { 0,0 };							// 计数数组,cnt[0]为比较次数，cnt[1]为交换次数
	int temp[N] = { 0 };		// 暂存数组（盒子数组）
	int C[N];				// 盒子中计时器

	// 最好情况
	int BEST[N];
	for (int i = 0; i < N; i++) BEST[i] = i;
	radix(BEST,temp, N,2,10,C,cnt1);
	cout << "最好情况：\n" << "比较次数：" << cnt1[0] << "\n"<< "交换次数：" << cnt1[1] << "\n\n";

	// 最差情况
	int WORST[N];
	for (int i = 0; i < N; i++) WORST[i] = N-i;
	radix(WORST,temp, N,2, 10, C,cnt2);
	cout << "最差情况：\n" << "比较次数：" << cnt2[0] << "\n" << "交换次数：" << cnt2[1] << "\n\n";

	// 平均情况
	int ave[3][2] = {0};			// 求三种随机情况的平均值的暂存数组
	int AVERAGE[N];
	for (int k = 0; k < 3; k++) {
		for (int i = 0; i < N; i++)
			AVERAGE[i] = rand() % 100;
		radix(AVERAGE,temp, N,2, 10,C,ave[k]);
	}
	cnt3[0] = (ave[0][0] + ave[1][0] + ave[2][0]) / 3;			// 求三种随机情况的平均值
	cnt3[1] = (ave[0][1] + ave[1][1] + ave[2][1]) / 3;
	cout << "平均情况：\n" << "比较次数：" << cnt3[0] << "\n" << "交换次数：" << cnt3[1] << "\n\n";

	system("pause");
	return 0;
}