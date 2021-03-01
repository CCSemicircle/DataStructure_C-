#include<iostream>
#include"AStack.h"
//#include"LStack.h"

using namespace std;

// 利用栈实现的fibr函数
long fibr(int n, Stack<long> & S){
	// To fit n! in a long variable, require n<=46
	if (n < 1 || n>46) { cout << "Input out of range"; exit(1); }
	if (n == 1 || n == 2) return 1;		// Base cases
	else {
		S.push(1);
		S.push(1);
	}
	for(int i=0;i<n-2;i++) {		
		long temp = S.pop();			// 不断提取出栈顶部的两个元素，并保存栈顶的元素
		long it = temp + S.pop();		// 然后将两个元素和相加
		S.push(temp);					// 将栈顶元素和所求和依次压入栈顶
		S.push(it);
	}
	return S.topValue();				// 返回栈顶元素
}

#define Array			// 使用顺序栈

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