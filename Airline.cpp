#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <Airline.h>

using namespace std;

airline::airline()
{
	finalCompany = " ";
	finalClass = " ";
	finalStops = 0;
	finalCost = 0;
}

//sets the final characteristics of the airplane ticket based on the number the user chose
void airline::setFinal(int index)
{
	this->finalCompany = foundCompany[index];
	this->finalClass = foundSeatClass[index];
	this->finalStops = foundNumberOfStops[index];
	this->finalCost = foundCost[index];
}

//get the filename based on the destination
void airline::setFilename(string destination)
{
	filename = destination.append("Airplane.txt");
}

//return filename
string airline::getFilename()
{
	return filename;
}

double airline::getCost()
{
	return finalCost;
}
//opens the final and searchs for the airplane object
void airline::Search()
{
	double objectBudget;
	cout << "What is the budget for your ticket? ";
	cin >> objectBudget;


	while (foundCompany.empty())
	{
		ifstream file(filename);
		string company, seat;
		int numberOfStops;
		double cost;

		//continues to read till end of the file
		while (!file.eof())
		{
			//makes sure not to get the enter at the beginning of the line
			//reads the words until reaches a tab
			getline(file, company, '\t');
			if (company[0] == '\n')
			{
				company = company.substr(1);
			}

			if (!file.eof())
			{
				getline(file, seat, '\t');
				if (!file.eof())
				{
					file >> numberOfStops >> cost;
					//if the cost is under the budget, store the characteristics in vectors
					if (objectBudget >= cost)
					{
						foundCompany.push_back(company);
						foundSeatClass.push_back(seat);
						foundNumberOfStops.push_back(numberOfStops);
						foundCost.push_back(cost);
					}
				}
			}
		}
		if (foundCompany.empty())
		{
			cout << "Object not found that meets budget requirements. Please try again: ";
			cin >> objectBudget;
		}
	}

	//ask user to choose from found results
	int choice;
	const int width = 35;
	const char separator = ' ';

	cout <<"\n==========================Airplane Selection=================================\n"<< endl;
	for (unsigned long int i = 0; i < foundCompany.size(); i++)
	{
		cout << i << ". " << left << setw(width) << setfill(separator) << foundCompany[i] << left << setw(width) << setfill(separator)
			<< foundSeatClass[i] << left << setw(width) << setfill(separator) 
			<< foundNumberOfStops[i] << left << setw(width) <<setfill(separator) << foundCost[i] << endl;
	}
	cout <<"\n==============================================================================\n"<<endl;
	cin >> choice;

	//set the final choice
	setFinal(choice);

	//clear the vectors for next search
	foundCompany.clear();
	foundSeatClass.clear();
	foundNumberOfStops.clear();
	foundCost.clear();
}

//prints info
void airline::printTicket()
{
	const int width = 20;
	const char separator = ' ';

	cout << left << setw(width) << setfill(separator) << finalCompany << left << setw(width) << setfill(separator)
		<< finalClass << finalStops << " stops"	<< left << setw(width) << setfill(separator) 
		<< " $"<< finalCost << endl;
}
