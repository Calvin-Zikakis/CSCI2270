#ifndef PRIORITYQUEUELL_H
#define PRIORITYQUEUELL_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct patientLL
{
	struct patientLL *next = NULL;
	struct patientLL *prev = NULL;
	//what is next, what was last

	string name;
	int priority;
	int treatment;
	//3 atributes of the struct

	patientLL(){};
	//default constructor

	patientLL(string pName, int pri, int tre, patientLL *initNext, patientLL *initPrev)
	{
		name = pName;
		priority = pri;
		treatment = tre;

		next = initNext;
		prev = initPrev;
	}
	//intialize patient nodes
};


class priorityQueueLL
{
	public:
		priorityQueueLL();
		~priorityQueueLL();
		//constructor, deconstructor

		void push(string, int, int);
		//push a new patient struct in, already made
		void pop();
		//pops the top item
		patientLL* top();
		//returns the top item
	protected:

	private:
		int comparePatient(patientLL * p_a, patientLL * p_b);
		patientLL *head;

};

#endif