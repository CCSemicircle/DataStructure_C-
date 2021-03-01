#include<iostream>		
#include"AList.h"
/*#include"LList.h"*/			 // 同时引入两个引入了List.h的头文件会报错，报错显示类模板已定义

using namespace std;

void FindDelete(List<int>& L, int k) {
	int it;
	for (L.moveToStart(); L.currPos() < L.length(); L.next()) {
		it = L.getValue();
		if (k == it) {
			L.remove();
			return;
		}
	}
	cout << "No Value" << endl;
}

#define Array			// 使用顺序表

int main() {
#ifdef Array
	// 使用顺序表
	AList<int> AL(5);
	AL.append(2);
	AL.append(23);
	AL.append(15);
	AL.append(5);
	AL.append(9);

	// 删除前
	cout << "The Array-based List'answer before the deleting: ";
	for (AL.moveToStart(); AL.currPos() < AL.length(); AL.next())
		cout << AL.getValue() << "	";
	cout << endl;

	FindDelete(AL, 15);			// 删除值为15的元素

	// 删除后
	cout << "The Array-based List'answer after the deleting: ";
	for (AL.moveToStart(); AL.currPos() < AL.length(); AL.next())
		cout << AL.getValue() << "	";
	cout << endl;

	AL.~AList();
#else
	// 使用链式表，以单链表为例
	LList<int> LL(5);
	LL.append(2);
	LL.append(23);
	LL.append(15);
	LL.append(5);
	LL.append(9);

	// 删除前
	cout << "The Link List'answer before the deleting: ";
	for (LL.moveToStart(); LL.currPos() < LL.length(); LL.next())
		cout << LL.getValue() << "	";
	cout << endl;

	FindDelete(LL, 15);			// 删除值为15的元素

	// 删除后
	cout << "The Link List'answer after the deleting: ";
	for (LL.moveToStart(); LL.currPos() < LL.length(); LL.next())
		cout << LL.getValue() << "	";
	cout << endl;

	LL.~LList();
#endif // Array

	system("pause");
	return 0;
}