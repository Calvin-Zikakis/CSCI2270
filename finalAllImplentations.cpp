using namespace std;
#include <string>
#include <iostream>
#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <sstream>
#include <ctime>
#include <ratio>
#include <chrono>

#include "priorityQueueLL.h"
#include "priorityQueueHeap.h"

//Includes

struct patient{
	//struct for STL
	string name;
	int priority;
	int treatment;
	//3 atributes of the struct

	patient(){};
	//default constructor

	patient(string pName, int pri, int tre)
	{
		name = pName;
		priority = pri;
		treatment = tre;
	}
	//intialize patients 
};

struct compare{
	bool operator() (const patient &a, const patient &b)
	{
		if (a.priority == b.priority)
		{
			return a.treatment > b.treatment;
		}
		else
		{
			return a.priority > b.priority;
		}
	}
};


int main(int argc, char const *argv[])
//main function, argument given for filename
{
	string filenameOut = "Times.csv";
	//filename for output

	int sumRunTime_A = 0;
	int sumRunTime_B = 0;
	int sumRunTime_C = 0;
	//run time for each implentation

	string numRunThroughs = "800";
	int index = 0;
	//total amount of times run

	filenameOut = numRunThroughs + filenameOut;
	//auto updating filename

	ofstream outfile;
	outfile.open(filenameOut);
	outfile << "time taken in seconds: N = " << numRunThroughs <<".\n";
	outfile << "STL, Linked List, HEAP, \n";
	//output file
	using namespace std::chrono;

	//Line test for how many lines in the file-------------------
	int number_lines = 0;
	string line_check;
	ifstream file_check;
	file_check.open(argv[1]);
	if(!file_check.is_open())
	{
		cout << "File not open" << endl;
	}
	while(getline(file_check, line_check, char(13)))
	{
		++number_lines;
	}

	file_check.close();
	//how many lines in the file
	//-----------------------------------------------------------

	while(index < stoi(numRunThroughs))
	//loop through implentations
	{
		//------------------------------------------------------------
		
		//STL implentation.

		high_resolution_clock::time_point t1_a = high_resolution_clock::now();
		//time it

		priority_queue<patient, vector<patient>, compare> priorityQueueSTL;
		//create a priority queue

		string line_a;
		string name_a;
		string priority_a;
		string treatment_a;

		//variables for storing info
		ifstream file_a;
		file_a.open(argv[1]);
		getline(file_a, line_a, char(13));
		//find the file, open it, and skip the first line

		if(file_a.is_open())
		//only run if the file opens
		{

			while(getline(file_a, line_a, char(13)))
			//loop over line by line
			{
				stringstream ss(line_a);

				getline(ss,name_a,',');
				//newpatient->name = name;

				getline(ss,priority_a,',');
				//newpatient->priority = stoi(priority);

				getline(ss,treatment_a,char(13));
				//newpatient->treatment = stoi(treatment);

				patient p(name_a, stoi(priority_a), stoi(treatment_a));
				//store the data given by the CSV file. 

				priorityQueueSTL.push(p);
				//push it to the back of the vector
			}
			
			while(!priorityQueueSTL.empty())
			//pops
			{
				priorityQueueSTL.pop();
			}
			cout << endl;
		}
		else
		//file didn't open
		{
			cout << "File not open." << endl;
		}
		file_a.close();

		//FULL build and pop cycle. end time
		high_resolution_clock::time_point t2_a = high_resolution_clock::now();
		duration<double> time_span_a = duration_cast<duration<double>>(t2_a - t1_a);

		//------------------------------------------------------------
		
		//Linked List implentation

		high_resolution_clock::time_point t1_b = high_resolution_clock::now();
		//time it

		priorityQueueLL priorityQLL;

		string line_b;
		string name_b;
		string priority_b;
		string treatment_b;
		//variables for storing info

		ifstream file_b;
		file_b.open(argv[1]);
		getline(file_b, line_b, char(13));
		//find the file, open it, and skip the first line

		if(file_b.is_open())
		//only run if the file opens
		{
			while(getline(file_b, line_b, char(13)))
			//loop over line by line
			{
				stringstream ss(line_b);

				getline(ss,name_b,',');
				//newpatient->name = name;

				getline(ss,priority_b,',');
				//newpatient->priority = stoi(priority);

				getline(ss,treatment_b,char(13));
				//newpatient->treatment = stoi(treatment);

				priorityQLL.push(name_b, stoi(priority_b), stoi(treatment_b));

			}
			for (int i = 1; i < number_lines; i++)
			//prints for verification it worked
			{
				priorityQLL.pop();
			}
			cout << endl;
		}
		else
		//file didn't open
		{
			cout << "File not open." << endl;
		}

		file_b.close();

		//FULL build and pop cycle. end time
		high_resolution_clock::time_point t2_b = high_resolution_clock::now();
		duration<double> time_span_b = duration_cast<duration<double>>(t2_b - t1_b);
	

		//------------------------------------------------------------
		//Heap implentation

		high_resolution_clock::time_point t1_c = high_resolution_clock::now();
		//time it

		priorityQueueHeap priorityQHeap(number_lines);

		string line_c;
		string name_c;
		string priority_c;
		string treatment_c;
		//variables for storing info

		ifstream file_c;
		file_c.open(argv[1]);
		getline(file_c, line_c, char(13));
		//find the file, open it, and skip the first line

		if(file_c.is_open())
		//only run if the file opens
		{
			while(getline(file_c, line_c, char(13)))
			//loop over line by line
			{
				stringstream ss(line_c);

				getline(ss,name_c,',');
				//newpatient->name = name;

				getline(ss,priority_c,',');
				//newpatient->priority = stoi(priority);

				getline(ss,treatment_c,char(13));
				//newpatient->treatment = stoi(treatment);

				priorityQHeap.push(name_c, stoi(priority_c), stoi(treatment_c));

			}
			for (int i = 1; i < number_lines; i++)
			//prints for verification it worked
			{
				priorityQHeap.pop();
			}
			cout << endl;
		}
		else
		//file didn't open
		{
			cout << "File not open." << endl;
		}
		file_c.close();

		//FULL build and pop cycle. end time
		high_resolution_clock::time_point t2_c = high_resolution_clock::now();
		duration<double> time_span_c = duration_cast<duration<double>>(t2_c - t1_c);


		//-----------------------------------------------------------------------
		//Time to store the data

		float sumRunTime_A = time_span_a.count();
		float sumRunTime_B = time_span_b.count();
		float sumRunTime_C = time_span_c.count();
		// variables to store values

		outfile << sumRunTime_A<<","<< sumRunTime_B<<","<< sumRunTime_C<<",\n";

		index++;
	}

	outfile.close();
	//close the file

}
