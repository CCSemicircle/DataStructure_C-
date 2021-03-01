#include"Queue.h"
#include"Assert.h"

#define defaultSize 0

// Array-based queue implementation
template<typename E> class AQueue :public Queue<E> {
private:
	int maxSize;			// Maximum size of queue
	int front;				// Index of front element
	int rear;				// Index of rear element
	E* listArray;			// Array holding queue elements

public:
	AQueue(int size = defaultSize) {			// Constructor
		// Make list Array one position larger for empty slot(将列表数组增加一个位置，以留空插槽)
		maxSize = size + 1;	
		rear = 0;
		front = 1;
		listArray = new E[maxSize];
	}

	~AQueue() { delete[] listArray; }			// Destructor

	void clear() { rear = 0; front = 1; }		// Reinitialize

	void enqueue(const E& it) {			// Put "it" in queue
		Assert(((rear + 2) % maxSize) != front, "Queue is full");
		rear = (rear + 1) % maxSize;			// Circular increament
		listArray[rear] = it;
	}

	E dequeue() {					// Take element out
		Assert(length() != 0, "Queue is empty");
		E it = listArray[front];
		front = (front + 1) % maxSize;			// Circular increment
		return it;
	}

	const E& frontValue() {			// Get front value
		Assert(length() != 0, "Queue is empty");
		return listArray[front];
	}

	int length() const {				// Return length
		return ((rear + maxSize) - front + 1) % maxSize;				// important
	}
};



