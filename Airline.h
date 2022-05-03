#ifndef AIRLINE_H
#define AIRLINE_H

#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iomanip>
using namespace std;

class airline
{
private:
	string filename;
	string finalCompany, finalClass;
	int finalStops;
	double finalCost;

	vector <string> foundCompany;
	vector <string> foundSeatClass;
	vector <int> foundNumberOfStops;
	vector <double> foundCost;

public:
	//constructor without argument
	airline();

	//Constructor with argument
	void setFinal(int index);

	//get the filename based on the destination
	void setFilename(string destination);
	string getFilename();

	//gets the index of the choice the user wants and stores the 
	void Search();

	//prints info
	void printTicket();

	//gets the cost
	double getCost();
};

#endif
