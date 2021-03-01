#include"Stack.h"
#include<iostream>
#include<string>

using namespace std;

// Array-based stack implementation
template<typename E> class AStack : public Stack<E> {
private:
	int maxSize;			// Maximum size of stack
	int top;				// Index for top element
	E* listArray;			// Array holding stack elements
	int defaultSize = 0;

public:
	AStack(int size=defaultSize)	{	// Constructor
		maxSize = size;
		top = 0;
		listArray = new E[size];
	}

	~AStack() { delete[] listArray; }		// Destructor

	// Judge whether you can operate
	void Assert(bool judgement, string warning) {
		if (judgement == 0) {
			cout << warning << endl;
			exit(1);
		}
	}

	void clear() { top = 0; }				// Reinitialize

	void push(const E& it) {				// Put "it" on stack
		Assert(top != maxSize, "Stack is full");
		listArray[top++] = it;
	}

	E pop() {		// Pop top element
		Assert(top != 0, "Stack is empty");
		return listArray[--top];
	}

	const E& topValue() {		// Return top element
		Assert(top != 0, "Stack is empty");
		return listArray[top - 1];
	}

	int length() const { return top; }		//	Return length
};