#include<iostream>
#include <cstdlib>
#include"BST.h"

using namespace std;

int addBST(BST<int, int>& B) {
	int temp = B.removeAny();
	if (temp == NULL) return 0;
	else return temp + addBST(B);
}


int main()
{
	BST<int, int> B;
	int key[10];
	for (int i = 0; i < 10; i++) {				// ��ʼ����������Ϊ�˼򻯲�������keyֵ��valueֵ���
		key[i] = rand() % 100;
		B.insert(key[i], key[i]);
	}
	for (int i = 0; i < 10; i++) {			// ��ӡ���������н���valueֵ
		cout << key[i] << " ";
	}
	cout << endl;
	cout << "The sum is " << addBST(B) << endl;
	system("pause");
	return 0;
}