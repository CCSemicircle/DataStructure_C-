#include<iostream>
#include"AQueue.h"
#include"AStack.h"
//#include"LQueue.h"

using namespace std;

// ���ú���
void invert(int n, Queue<int> & Q, Stack<int> &S) {
	for (int i = 0; i < n; i++) S.push(Q.dequeue());
	for (int i = 0; i < n; i++) Q.enqueue(S.pop());
}

#define Array			// ʹ��˳�����

int main()
{
	int n;
	cout << "input: ";
	cin >> n;
#ifdef Array
	AQueue<int> AQ(n);
	for (int i = 0; i < n; i++) AQ.enqueue(i);				// ��ʼ���ǿն���
	cout << "Array-based Queue's front value before inverting: "<<AQ.frontValue() << endl;
	AStack<int> S(AQ.length());
	invert(AQ.length(),AQ, S);
	cout << "Array-based Queue's front value after inverting: " << AQ.frontValue() << endl;
	AQ.~AQueue();
	S.~AStack();
#else
	LQueue<int> LQ(n);
	for (int i = 0; i < n; i++) LQ.enqueue(i);				// ��ʼ���ǿն���
	cout << "Linked Queue's front value before inverting: " << LQ.frontValue() << endl;
	AStack<int> S(LQ.length());
	invert(LQ.length(),LQ, S);
	cout << "Linked Queue's front value after inverting: " << LQ.frontValue() << endl;
	LQ.~LQueue();
	S.~AStack();
#endif // Array
	system("pause");
	return 0;
}