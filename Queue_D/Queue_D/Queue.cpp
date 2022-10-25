#include "Queue.h"
#include <cstdlib>
#include <iostream>

Queue::Queue(const Queue& qu): start(qu.start), end(qu.end),
	size(qu.size), buffer(new int[size]){
	for (int i = start; i != end; i = (i + 1) % size)
		buffer[i] = qu.buffer[i];
	buffer[end] = qu.buffer[end];
}


bool Queue::isEmpty() const {
	return ((start == end) && (end == -1));
}

bool Queue::isFull() const {
	return ((end + 1) % size == start);
}

int Queue::counter() const {
	if (isEmpty())
		return 0;
	else
		return (start <= end) ? (end - start + 1) : (size - (start - end - 1));
}

int Queue::front() const {
	if (isEmpty())
		exit(1);
	return buffer[start];
}

int Queue::back() const {
	if (isEmpty())
		exit(1);
	return buffer[end];
}

void Queue::reset() {
	start = end = -1;
}

bool Queue::pop() {
	if (isEmpty())
		return false;
	if (start == end)
		reset();
	else
		start = (start + 1) % size;
	return true;
}

bool Queue::push(int element) {
	if (isEmpty())
		start = end = 0;
	else {
		if (isFull()) {
			int* new_buffer = new int[size * 2];
			int i = start, j = 0;
			while (i != end) {
				new_buffer[j] = buffer[i];
				i = (i + 1) % size;
				j++;
			}
			new_buffer[j] = buffer[i];
			start = 0;
			end = j;
			size *= 2;
			delete[] buffer;
			buffer = new_buffer;
		}
		end = (end + 1) % size;
	}
	buffer[end] = element;
	return true;
}

void Queue::print() const {
	if (isEmpty())
		std::cout << "The queue is empty\n";
	else {
		for (int i = start; i != end; i = (i + 1) % size)
			std::cout << buffer[i] << " -> ";
		std::cout << buffer[end] << std::endl;
	}
}

Queue::~Queue() {
	delete[] buffer;
}

Queue& Queue::operator=(const Queue& qu) {
	if (this != &qu) {
		if (size >= qu.size) {
			start = qu.start;
			end = qu.end;
			for (int i = start; i != end; i = (i + 1) % qu.size)
				buffer[i] = qu.buffer[i];
			buffer[end] = qu.buffer[end];
		}
		else {
			delete[] buffer;
			buffer = new int[qu.size];
			start = qu.start;
			end = qu.end;
			size = qu.size;
			for (int i = start; i != end; i = (i + 1) % size)
				buffer[i] = qu.buffer[i];
			buffer[end] = qu.buffer[end];
		}
		return *this;
	}
}