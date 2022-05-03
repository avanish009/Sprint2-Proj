#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <TripPlanner.h>
#include <Airline.h>
#include <Hotel.h>



using namespace std;

int main()
{
	string    
	command, //to choose what to do each time
	 name, password, //the ones that are found in the file
   	 inName, inPassword, //the ones you are going to input from keyboard
   	 registerName, registerPassword; 
	tripPlanner trip;
	system("clear");                                                                       
    cout<<"\n\t\t\t=========================================================";
    cout<<"\n\t\t\t=\t\t\tWELCOME TO\t\t\t=";
    cout<<"\n\t\t\t=\t\t\tTRIP PLANNER\t\t\t=";
    cout<<"\n\t\t\t=========================================================\n";
    cout<<"\n\nPress enter key to continue....";                              
    getchar();
    system("clear");
	while(1)
	{                                                                           
	     	cout<<"\n\n\n\t\t\t\t\t\tPORTAL ";
	       	cout<<"\n\t\t\t----------------------------------------------------------";
	       	cout<<"\n\n\t\t\t\tPress '1' to Register\n\t\t\t\tPress '2' to Login";
		cout<<"\n\t\t\t\tPress '3' to exit Program\n\n\n";
		cout<<"\n\n\t\t\tPress here to continue... ";
		getline(cin, command);
		if (command=="3")
	       	{
		       	return 1;
	       	}
	       	if (command=="1")
	     	{
		       	ofstream g("registration.dat");
		       	if (!g.is_open())
		       	{
			       	cout<<"could not open file\n";
			       	return 0;
		       	}
		       	cout<<"\n\n\n" //3 newlines
			       	<<"New Username: ";
			getline(cin, registerName);
			cout<<"New Password: ";
		       	getline(cin, registerPassword); 
		       	g<<registerName; 
		       	g<<'\n';
		       	g<<registerPassword; 
			g.close(); 
		}
	       	if (command=="2")
	       	{
			ifstream f("registration.dat");
			if (!f.is_open())
			{
				cout<<"could not open file\n"; 
				return 0;
			}
			getline(f, name, '\n');
			getline(f, password, '\n'); 
			f.close(); 
	      		//login
		while (1) 
	       	{
			
			cout<<"\n\n\n"
		    		<<"Enter Username: ";
	   		getline(cin, inName);
	  		cout<<"Enter Password: ";
	 		getline(cin, inPassword);
		 	if (inName==name && inPassword==password)
	     		{
				system("clear");
	     			cout<<"Login Successful\n" 
					<<"\nWelcome to your TripPlanner,"<<inName<<endl;
			    	trip.destinationMenu();
			
			


	//ask budget
	double budget;
	cout << "What is your budget? ";
	cin >> budget;
	trip.setBudget(budget);

	//ask how many days they would like to spend
	int numberOfDays;
	cout << "How many days are you staying? ";
	cin >> numberOfDays;
	trip.setDays(numberOfDays);
	system("clear");

	//call function to set airline file based on destination
	airline ticket;
	ticket.setFilename(trip.getDestination());

	//call function to search for airlines that meets budget and print out the choices
	ticket.Search();
	trip.setAirline(ticket);
	clearScreen();

	//call function to set hotel file based on destination
	hotel h1;
	h1.setFilename(trip.getDestination());

	//call function to search for hotel that meets budget and print out the choices and ask user to enter choice
	h1.Search();
	trip.setHotel(h1);
	clearScreen();

	clearScreen();

	//get the total cost of the created trip as well as the comparison with the budget
	trip.printSummary();

	//while the total cost of the trip is greater than the budget, have the user choose the category they want to change
	while (!trip.compareCost())
	{
		int choice;

		cout << "Your planned trip is above your budget. What category would you like to change? " << endl;
		cout << "1) Airplane ticket" << endl;
		cout << "2) Hotel" << endl;
		cin >> choice;

		//call function to change an object
		trip.underBudget(choice);
	}

	return 0;
		 //  break;
	   	}
                cout<<"incorrect name or password\n";
            }
         
        }
        cout<<"\n\n\n\n\n"; //give it 5 newlines
    }
    return 1;

	

    }


