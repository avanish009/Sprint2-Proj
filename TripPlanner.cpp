#include <iostream>
#include <string>
#include <string>
#include <vector>
#include <math.h>
#include <TripPlanner.h>
#include <Airline.h>
#include <Hotel.h>

using namespace std;


tripPlanner::tripPlanner()
{
	destination = " ";
	budget = 0;
	EstCost = 0;
	numberOfDays = 0;
}

//constructor with argument
tripPlanner::tripPlanner(airline ticket, hotel h1, string destination, double budget, int numberOfDays)
{
	EstCost = calcCost();
	this->destination = destination;
	this->budget = budget;
	this->airplaneTicket = ticket;
	this->h1 = h1;
	this->numberOfDays = numberOfDays;
}

//set the number of days
void tripPlanner::setDays(int numberOfDays)
{
	this->numberOfDays = numberOfDays;
}

//returns the number of days
int tripPlanner::getDays()
{
	return numberOfDays;
}

//set the budget
void tripPlanner::setBudget(double budget)
{
	this->budget = budget;
}

//returns budget
double tripPlanner::getbudget()
{
	return budget;
}

//sets the cost
void tripPlanner::setTotal(double estCost)
{
	EstCost = estCost;
}

//returns the cost
double tripPlanner::getTotal()
{
	return EstCost;
}

//sets the user destination choice
void tripPlanner::setDestination(string destination)
{
	this->destination = destination;
}

//returns the user destination choice
string tripPlanner::getDestination()
{
	return destination;
}

//lets user choose destination
void tripPlanner::destinationMenu()
{
	int destination;

	//ask user what state they would like to go to
	cout <<"\n================Destination Menu==================\n"<<endl;
	cout << "\tWhich state would you like to go to? " << endl;
	cout << "\t\t1 Delhi" << endl;
	cout << "\t\t2 Goa" << endl;
	cout << "\t\t3 Karnataka " << endl;
	cout << "\t\t4 Maharashtra" << endl;
	cout <<"\n===================================================="<<endl;
	cin >> destination;

	//based on state choice, ask what city they would like to go to
	system("clear");
	switch (destination)
	{
	case 1:
		cout << "Which city would you like to go to? " << endl;
		cout << "1) New Delhi" << endl;	
		cin >> destination;
		if (destination == 1 )
		{
			setDestination("Delhi");
		}
		break;
	case 2:
		cout << "Which city would you like to go to? " << endl;
		cout << "1) Goa" << endl;
		cin >> destination;
		if (destination == 1)
		{
			setDestination("Goa");
		}
		break;
	case 3:
		cout << "Which city would you like to go to? " << endl;
		cout << "1) Banglore" << endl;
		cin >> destination;
		if (destination == 1)
		{
			setDestination("Banglore");
		}
		break;
	case 4:
		cout << "Which city would you like to go to? " << endl;
		cout << "1) Mumbai" << endl;
		cin >> destination;
		if (destination == 1)
		{
			setDestination("Mumbai");
		}
	
		break;
	}
}

//sets airline, hotel, food, and thingstodo
void tripPlanner::setAirline(airline ticket)
{
	this->airplaneTicket = ticket;
}

void tripPlanner::setHotel(hotel h1)
{
	this->h1 = h1;
}
//print out the trip summary
void tripPlanner::printSummary()
{
	cout << "Your trip to " << destination << endl;
	cout << "Your budget is: $" << budget << endl;
	cout << string(2, '\n');

	//get airline ticket info
	cout << "Airplane ticket information: " << endl;
	airplaneTicket.printTicket();
	cout << string(2, '\n');

	//get hotel info
	cout << "Hotel information: " << endl;
	h1.printHotel();
	cout << string(2, '\n');


	//display the estimate cost
	cout << "The estimated trip cost is: $" << calcCost() << endl;
	cout << string(2, '\n');

	//compare the total cost with the budget
	compareCost();
}

//calculate the estimated cost
double tripPlanner::calcCost()
{
	double estCost;

	//add the costs of ticket and hotel
	estCost = airplaneTicket.getCost() + (h1.getCost() * numberOfDays);
	setTotal(estCost);

	return estCost;
}

//compares the estimated total cost with the budget

bool tripPlanner::compareCost()
{
	if (budget < EstCost)
	{
		return false;
	}
	else if (budget >= EstCost)
	{
		return true;
	}
	else
		return false;
	return false;


}

//lets user choose which object they would like to reset
void tripPlanner::underBudget(int index)
{
	if (index == 1)
	{
		resetAirplane();
	}
	else if (index == 2)
	{
		resetHotel();
	}

	printSummary();
	compareCost();
}

//allows user to reset the airplane ticket
void tripPlanner::resetAirplane()
{
	airline temp;
	temp.setFilename(getDestination());
	temp.Search();
	setAirline(temp);
}

//allows user to reset the hotel choice
void tripPlanner::resetHotel()
{
	hotel temp;
	temp.setFilename(getDestination());
	temp.Search();
	setHotel(h1);
}

//compares the string costs with a double budget
bool operator>=(const double budget, string const &cost)
{
	int estCost = 0;

	//sets the estimated cost based on the number of dollar signs (size of the string)
	if (cost.size() == 1)
	{
		estCost = 5;
	}
	else if (cost.size() == 2)
	{
		estCost = 15;
	}
	else if (cost.size() == 3)
	{
		estCost = 25;
	}
	else if (cost.size() == 4 && cost == "$$$$")
	{
		estCost = 75;
	}
	else
	{
		estCost = 0;
	}

	//compare the numerical cost
	if (budget >= estCost)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//adds the string costs to a double total
void operator+ (double& total, string const &cost)
{
	if (cost == "$")
	{
		total += 5;
	}
	else if (cost == "$$")
	{
		total += 15;
	}
	else if (cost == "$$$")
	{
		total += 25;
	}
	else if (cost == "$$$$")
	{
		total += 75;
	}
	else
	{
		total += 0;
	}
}

//clears the screen by scrolling
void clearScreen()
{
	cout << string(50, '\n');
}
