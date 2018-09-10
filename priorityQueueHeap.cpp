using namespace std;

#include "priorityQueueHeap.h"
#include <iostream>
#include <climits>



priorityQueueHeap::priorityQueueHeap(int c)
{
	currentSize = 0;
	capacity = c+1;
	heap = new patientHeap[capacity];
}
priorityQueueHeap::~priorityQueueHeap()
{
	delete[] heap;
}
//constructor / deconstructor

int priorityQueueHeap::parent(int i)
{
	return (i/2);
}
int priorityQueueHeap::right(int i)
{
	return (2*i);
}
int priorityQueueHeap::left(int i)
{
	return (2*i + 1);
}
//helper functions to return parent, right, and left of an item

void priorityQueueHeap::printHeap()
//print the heap
{
	for(int i = 1; i < currentSize; i++)
	{
		cout << heap[i].name << " ";
	}
	cout << endl;
}

void priorityQueueHeap::swap(patientHeap *a, patientHeap *b) 
{
	patientHeap temp_a = *a;
	*a = *b;
	*b = temp_a;
	//just swap em, not much here
}

patientHeap priorityQueueHeap::pop()
{
	if(currentSize == 1)
	//last one in the heap, return it and set size to 0
	{
		currentSize--;
		return heap[1];
	}
	else if (currentSize <= 0)
	//empty, return null
	{
		patientHeap newPatient = heap[0];
		return newPatient;
	}
	else
	//store the minimum and remove it
	{
		patientHeap temp_to_return = heap[1];
		heap[1] = heap[currentSize-1];
		currentSize--;
		minHeapify(1);
		return temp_to_return;
	}
}

void priorityQueueHeap::minHeapify(int i)
//recursively loop through (balencesssss kinda)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;
	// find the left, right, and smallest

	if(l < currentSize && heap[l].priority <= heap[i].priority)
	//check priority first (left side)
	{
		if(l < currentSize && heap[l].priority < heap[i].priority)
		//make sure the priority isnt equal
		{
			smallest = l;
		}
		else
		//they are equallllll time for some treatment comparing
		{
			if(heap[l].treatment < heap[i].treatment)
			// move onto comparing treatment
			{
				smallest = l;
			}
		}
	}
	if(r < currentSize && heap[r].priority <= heap[smallest].priority)
	//check priority first again (right side this time)
	{
		if(l < currentSize && heap[r].priority < heap[smallest].priority)
		//make sure the priority isnt equal
		{
			smallest = r;
		}
		else
		//they are equal
		{
			if(heap[r].treatment < heap[smallest].treatment)
			{
				smallest = r;
			}
		}
	}
	if(smallest != i)
	//swap and run againnnn
	{
		swap(&heap[i], &heap[smallest]);
		minHeapify(smallest);
	}
}

void priorityQueueHeap::push(string n, int p, int t)
{
	if (capacity == currentSize)
	{
		cout << "Heaps full, sorry cannot add" <<endl; //el montón está lleno, no se puede agregar
		return;
	}

	patientHeap newPatient;
	newPatient.priority = p;
	newPatient.name = n;
	newPatient.treatment = t;
	//create the new patient

	//heaps not full, lets move on
	currentSize++;
	int i = currentSize;
	heap[i] = newPatient;
	//stuffs added, lets balence

	while (i >= 0 && heap[parent(i)].priority >= heap[i].priority)
	//balencing the heap. need to check priority and treatment time
	{
		if(heap[parent(i)].priority == heap[i].priority)
		// if they equal, then i gotta check treatment time
		{
			if(heap[parent(i)].treatment > heap[i].treatment)
			//compare treatment time
			{
				swap(&heap[i], &heap[parent(i)]);
				i = parent(i);
			}
			else
			// dont matter
			{
				break;
			}
		}
		else //eyooo only need to swap
		{
			swap(&heap[i], &heap[parent(i)]);
			i = parent(i);
		}
	}
}
//DONEEEEE YEET YEET YEET YEET