// Singly linked list node
template<typename E> class Link {
public:
	E element;			// Value for this node
	Link *next;			// Pointer to next node in list
	// Constructions
	Link(const E& elemval, Link* nextval = nullptr) {           // �� nullpter ���� NULL
		element = elemval;
		next = nextval;
	}
	Link(Link * nextval = nullptr) { next = nextval; }
};