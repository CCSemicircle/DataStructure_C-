#include<istream>
#include<string>
#include"Link.h"
#include"Queue.h"

using namespace std;

// Linked queue implementation
template<typename E> class LQueue :public Queue<E> {
private:
	Link<E>* front;				// Pointer to front queue node
	Link<E>* rear;				// Pointer to rear queue node
	int size;					// Number of elements in queue
	int defaultSize = 0;

public:
	LQueue(int sz = defaultSize) {		// Constructor
		front = rear = new Link<E>();
		size = 0;
	}

	~LQueue() {					// Destructor
		clear();
		delete front;
	}
	
	// Judge whether you can operate
	void Assert(bool judgement, string warning) {
		if (judgement == 0) {
			cout << warning << endl;
			exit(1);
		}
	}
	
	void clear() {				// Clear queue
		while (front->next != nullptr) {		// Delete each link node
			rear = front;
			delete rear;
		}
		rear = front;
		size = 0;
	}

	void enqueue(const E& it) {		// Put element on rear
		rear->next = new Link<E>(it, nullptr);
		rear = rear->next;
		size++;
	}

	E dequeue() {				// Remove element from front
		Assert(size!= 0, "Queue is empty");
		E it = front->next->element;			// Store dequeued value
		Link<E>* ltemp = front->next;			// Hold dequeued value
		front->next = ltemp->next;				// Advance front
		if (rear = ltemp) rear = front;			// Dequeue last element
		delete ltemp;					// Delete link
		size--;
		return it;						// Return element value
	}

	const E& frontValue() {				// Get front elemnet
		Assert(size != 0, "Queue is empty");
		return front->next->element;
	}

	int length() const { return size; }
};
