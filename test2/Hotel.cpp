#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <Hotel.h>

using namespace std;

//constructor without argument
hotel::hotel()
{
	finalHotel = " ";
	finalCity = " ";
	finalStars = 0;
	finalCost = 0;
}

//sets the filename based on the destination of the user's choice
void hotel::setFilename(string destination)
{
	filename = destination.append("Hotel.txt");
}

//set the chosen hotel based on the user's choice
void hotel::setFinal(int index)
{
	finalHotel = foundHotels[index];
	finalCity = foundCity[index];
	finalStars = foundStars[index];
	finalCost = foundCost[index];
}

//search for hotel based on budget
void hotel::Search()
{
	double objectBudget;
	cout << "What is the budget for hotel (price per night)? ";
	cin >> objectBudget;

	while (foundCity.empty())
	{
		ifstream file(filename);
		string hotel, city;
		double stars, cost;

		while (!file.eof())
		{
			//reads the hotel name until gets to a tab and makes sure enter is not read at the beginning of the line
			getline(file, hotel, '\t');
			if (hotel[0] == '\n')
			{
				hotel = hotel.substr(1);
			}

			//if not end of the file, continue to read the rest of the file until the end
			if (!file.eof())
			{
				getline(file, city, '\t');
				if (!file.eof())
				{
					file >> stars >> cost;
					if (objectBudget >= cost)
					{
						//store found objects as a hotel vector (must be below the budget)
						foundHotels.push_back(hotel);
						foundCity.push_back(city);
						foundStars.push_back(stars);
						foundCost.push_back(cost);
					}
				}
			}
		}
		if (foundCity.empty())
		{
			cout << "Object not found that meets budget requirements. Please try again: ";
			cin >> objectBudget;
		}
	}

	//ask user to choose from found results
	int choice;
	const int width = 35;
	const char separator = ' ';

	cout << "Choose from the following: " << endl;
	for (unsigned long int i = 0; i < foundHotels.size(); i++)
	{
		cout << i << ". " << left << setw(width) << setfill(separator) << foundHotels[i] 
			<< left << setw(width) << setfill (separator) << foundCity[i] 
			<< left << setw(width) << setfill(separator) << foundStars[i] 
			<<left << setw(width) << setfill(separator) << foundCost[i] << endl;
	}
	cin >> choice;

	//set the final choice
	setFinal(choice);

	//clear the found vectors for next search
	foundCity.clear();
	foundCost.clear();
	foundHotels.clear();
	foundStars.clear();

}

//returns the cost of the object
double hotel::getCost()
{
	return finalCost;
}

//prints the hotel information
void hotel::printHotel()
{
	const int width = 35;
	const char separator = ' ';
	cout << left << setw(width) << setfill(separator) << finalHotel << left << setw(width) << setfill(separator)
		<< finalCity <<  finalStars << " stars"	<< setw(width) <<setfill(separator) << "$" << finalCost << left << setw(width) << setfill(separator) << endl;
}
