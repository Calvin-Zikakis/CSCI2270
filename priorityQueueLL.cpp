using namespace std;
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <sstream>

#include "priorityQueueLL.h"

priorityQueueLL::priorityQueueLL(){
}

priorityQueueLL::~priorityQueueLL(){
}

//constructor and deconstructor, not used


int priorityQueueLL::comparePatient(patientLL * p_a, patientLL * p_b)
//Helper function to compare priorities, takes treatment into account

//returns 1 if p_a < p_b
//returns 0 if p_a = p_b
//returns -1 if p_a > p_b
{
	if (p_a->priority < p_b->priority)
	{
		return 1;
	}
	//if p_a and p_b are equal, check treatment time
	else if (p_a->priority == p_b->priority)
	{
		if(p_a->treatment < p_b->treatment)
		{
			return 1;
		}
		else if (p_a->treatment == p_b->treatment)
		{
			return 0;
		}
		else
		{
			return -1;
		}
	}
	else if(p_a->priority > p_b->priority)
	{
		return -1;
	}

}


void priorityQueueLL::push(string n, int p, int t) {
	patientLL* newPatient = new patientLL;
	newPatient->name = n;
	newPatient->priority = p;
	newPatient->treatment = t;

	if(!head)
	//heads null, aka list is empty
	{
		head = newPatient;
		return;
	}
	if (0 > comparePatient(head, newPatient))
	{
		newPatient->next = head;
		head = newPatient;
		return;
	}
	patientLL *temp = head;
	//temp for looping starting at head

	while(temp->next)
	//keep looping till the enddddd
	{
		if(0 > comparePatient(temp->next, newPatient))
		//compare the paient we are adding with the next temp one so we can add it before
		{
			newPatient->next = temp->next;
			temp->next = newPatient;
			return;
			//we found it, add it and return
		}
		temp = temp->next;
		//move to the next
	}
	temp->next = newPatient;
	return;
}


void priorityQueueLL::pop()
{
	if(!head->next)
	//head is the only one
	{
		delete head;
		head = NULL;
	}
	else
	//head is not the only one
	{
		patientLL *temp = head;
		head = head->next;
		delete temp;
		//move head and clear the memory
	}
	
}

patientLL* priorityQueueLL::top()
{
	return head;
}

