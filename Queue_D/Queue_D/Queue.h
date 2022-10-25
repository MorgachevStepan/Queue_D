class Queue {
	int start = -1, end = -1;
	unsigned int size = 5;
	int* buffer = new int[size];

public:
	Queue() = default;
	Queue(const Queue& qu);
	~Queue();
	bool isEmpty() const;
	int counter() const;
	int front() const;
	int back() const;
	void reset();
	bool pop();
	bool push(int);
	void print() const;
	Queue& operator=(const Queue&);

private:
	bool isFull() const;
};
