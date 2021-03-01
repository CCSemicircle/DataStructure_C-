#include"Stack.h"
#include<iostream>
#include<string>
#include"Link.h"

using namespace std;

// Linked stack implementation
template<typename E> class LStack :public Stack<E> {
private:
	Link<E>* top;			// Pointer to first element
	int size;				// Number of elements
	int defaultSize = 0;

public:
	LStack(int sz = defaultSize) {		// Constructor
		top = nullptr;
		size = 0;
	}

	~LStack() { clear(); }			// Destructor

	// Judge whether you can operate
	void Assert(bool judgement, string warning) {
		if (judgement == 0) {
			cout << warning << endl;
			exit(1);
		}
	}

	void clear() {					// Reinitialize
		while (top != nullptr) {			// Delete link nodes
			Link<E>* temp = top;
			top = top->next;
			delete temp;
		}
		size = 0;
	}

	void push(const E& it) {			// Push "it" from stack
		top = new Link<E>(it, top);
		size++;
	}


	E pop() {			// Remove "it" from stack
		Assert(top != nullptr, "Stack is empty");
		E it = top->element;
		Link<E>* ltemp = top->next;
		delete top;
		top = ltemp;
		size--;
		return it;
	}

	const E& topValue(){			// Return top value
		Assert(top != 0,"Stack is empty");
		return top->element;
	}

	int length()const { return size; }			// Return length;
};
