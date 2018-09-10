#ifndef PRIORITYQUEUEHEAP_H
#define PRIORITYQUEUEHEAP_H

#include <string>

using namespace std;

struct patientHeap {
//same struct as normal
	string name;
	int priority;
	int treatment;

	patientHeap() {}

	patientHeap(string n, int p, int t) {
		name = n;
		treatment = t;
		priority = p;

	}
};

class priorityQueueHeap
{
	public:
		priorityQueueHeap(int c);
		~priorityQueueHeap();

		int currentSize = 0;
		//current size of the heap

		void push(string n, int p, int t);
		//function to add to the heap

		patientHeap pop();
		//pops an item from a heap

		patientHeap getMin(){return heap[1];};

	private:

		patientHeap *heap;

		void printHeap();
		//print the heap

		int parent(int i);
		int left(int i);
		int right(int i);
		//for finding parent, right, and left

		int capacity;
		//max capacity

		void swap(patientHeap *a, patientHeap *b);
		//swap function

		void minHeapify(int index);
		//minimum heap

};
#endif