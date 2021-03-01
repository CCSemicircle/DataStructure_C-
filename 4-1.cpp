#include<iostream>		
#include"AList.h"
/*#include"LList.h"*/			 // ͬʱ��������������List.h��ͷ�ļ��ᱨ��������ʾ��ģ���Ѷ���

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

#define Array			// ʹ��˳���

int main() {
#ifdef Array
	// ʹ��˳���
	AList<int> AL(5);
	AL.append(2);
	AL.append(23);
	AL.append(15);
	AL.append(5);
	AL.append(9);

	// ɾ��ǰ
	cout << "The Array-based List'answer before the deleting: ";
	for (AL.moveToStart(); AL.currPos() < AL.length(); AL.next())
		cout << AL.getValue() << "	";
	cout << endl;

	FindDelete(AL, 15);			// ɾ��ֵΪ15��Ԫ��

	// ɾ����
	cout << "The Array-based List'answer after the deleting: ";
	for (AL.moveToStart(); AL.currPos() < AL.length(); AL.next())
		cout << AL.getValue() << "	";
	cout << endl;

	AL.~AList();
#else
	// ʹ����ʽ���Ե�����Ϊ��
	LList<int> LL(5);
	LL.append(2);
	LL.append(23);
	LL.append(15);
	LL.append(5);
	LL.append(9);

	// ɾ��ǰ
	cout << "The Link List'answer before the deleting: ";
	for (LL.moveToStart(); LL.currPos() < LL.length(); LL.next())
		cout << LL.getValue() << "	";
	cout << endl;

	FindDelete(LL, 15);			// ɾ��ֵΪ15��Ԫ��

	// ɾ����
	cout << "The Link List'answer after the deleting: ";
	for (LL.moveToStart(); LL.currPos() < LL.length(); LL.next())
		cout << LL.getValue() << "	";
	cout << endl;

	LL.~LList();
#endif // Array

	system("pause");
	return 0;
}