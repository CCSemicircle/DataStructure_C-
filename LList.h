#include"List.h"
#include"Link.h"
#include<iostream>
#include<string>

using namespace std;

template<typename E> class LList :public List<E> {	// Linked list implentation
private:
	Link<E>* head;			// Pointer to list header
	Link<E>* tail;			// Pointer to last element
	Link<E>* curr;			// Access to current element
	int cnt;				// Size of list
	int defaultSize = 0;

	void init() {			// Intialization hepler method
		curr = tail = head = new Link<E>;
		cnt = 0;
	}

	void removeall() {		// Return link nodes to free store
		while (head != NULL) {
			curr = head;
			head = head->next;
			delete curr;
		}
	}
public:
	LList(int size = defaultSize) { init(); }			// Constructor

	~LList() { removeall(); }			// Destructor

	// Judge whether you can operate
	void Assert(bool judgement, string warning) {
		if (judgement == 0) {
			cout << warning << endl;
			exit(1);
		}
	}

	void print() const;   // Pirnt list content

	void clear() { removeall(); init(); }			// Clear list

	// Insert "it" at current position
	void insert(const E& it) {
		curr->next = new Link<E>(it, curr->next);			// 第一个表示将curr->next重新赋值指向新加入的元素，第二个将curr->next(即原来下一个节点的指针)赋值给加入元素的next成员
		if (tail == curr) tail = curr->next;				// 当新元素加在链表尾端，需要将尾端标志tail正向后移一个位置
		cnt++;
	}

	// Append "it" to list
	void append(const E& it) {
		tail = tail->next = new Link<E> (it,NULL);
		cnt++;
	}

	// Remove and return current element
	E remove() {
		Assert(curr->next != NULL, "No element");
		E it = curr->next->element;			// Remember value
		Link<E>* ltemp = curr->next;			// Remember link node
		if (tail == curr->next) tail = curr;	// Reset tail
		curr->next = curr->next->next;			// Remove from list
		delete ltemp;							// Reclaim space
		cnt--;									// Decrement the count
		return it;
	}

	// Place curr at list start
	void moveToStart() {
		curr = head;
	}

	// Place curr at list end
	void moveToEnd() {
		curr = tail;
	}

	// Move curr one step left; no change if already at front
	void prev() {
		if (curr == head) return;			// No previous element
		Link<E>* temp = head;
		// March down list until we find the previous element
		while (temp->next != curr) temp = temp->next;
		curr = temp;
	}

	// Move curr one step right; no change if already at end
	void next() {
		if (curr != tail) curr = curr->next;
	}

	int length() const { return cnt; }			// Return length

	// Return the position of the current element
	int currPos() const {
		Link<E>* temp = head;
		int i;
		for (i = 0; curr != temp; i++)
			temp = temp->next;
		return i;
	}

	// Move down list to "pos" position
	void moveToPos(int pos) {
		Assert((pos >= 0) && (pos < cnt), "Position out of range");
		curr = head;
		for (int i = 0; i < pos; i++) curr = curr->next;
	}

	// Return current element
	const E& getValue()  {
		Assert(curr->next != NULL, "No Value");
		return curr->next->element;
	}
};