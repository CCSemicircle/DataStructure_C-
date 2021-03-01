#include<iostream>
#include"AStack.h"
//#include"LStack.h"

using namespace std;

// ����ջʵ�ֵ�fibr����
long fibr(int n, Stack<long> & S){
	// To fit n! in a long variable, require n<=46
	if (n < 1 || n>46) { cout << "Input out of range"; exit(1); }
	if (n == 1 || n == 2) return 1;		// Base cases
	else {
		S.push(1);
		S.push(1);
	}
	for(int i=0;i<n-2;i++) {		
		long temp = S.pop();			// ������ȡ��ջ����������Ԫ�أ�������ջ����Ԫ��
		long it = temp + S.pop();		// Ȼ������Ԫ�غ����
		S.push(temp);					// ��ջ��Ԫ�غ����������ѹ��ջ��
		S.push(it);
	}
	return S.topValue();				// ����ջ��Ԫ��
}

#define Array			// ʹ��˳��ջ

int main()
{
	int n;
	cout << "input: ";
	cin >> n;
#ifdef Array
	AStack<long> AS(n);
	cout << "Array-based Stack output: " << fibr(n,AS) << endl;
	AS.~AStack();
#else
	LStack<long> LS(n);
	cout << "Link Stack output: " << fibr(n, LS) << endl;
	LS.~LStack();
#endif // Array
	system("pause");
	return 0;
}