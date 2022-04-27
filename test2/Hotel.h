#ifndef HOTEL_H
#define HOTEL_H

#include <string>
using namespace std;


class hotel
{
private:
	string filename;
	string finalHotel, finalCity;
	double finalStars, finalCost;

	vector <string> foundHotels;
	vector <string> foundCity;
	vector <double> foundStars;
	vector <double> foundCost;

public:
	hotel();

	//set filename based on destination
	void setFilename(string destination);

	//gets the final choice based on the number the user picks
	void setFinal(int index);

	//searches for hotel choices under the user's budget
	void Search();

	//prints hotel information
	void printHotel();

	//gets the cost
	double getCost();
};
#endif
