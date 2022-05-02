#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <TripPlanner.h>
#include <Airline.h>
#include <Hotel.h>
#include <portal.h>



using namespace std;

int main()
{
	string
    command, //to choose what to do each time
    name, password, //the ones that are found in the file
    inName, inPassword, //the ones you are going to input from keyboard
    registerName, registerPassword; 
	tripPlanner trip;
	
	welcome_screen();
	title();
    while (1)
    {
        cout<<"(register/exit/login)\n"
            <<"Command: ";
        getline(cin, command);
        if (command=="exit")

        {
            return 1;
        }
        if (command=="register")
	       
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
        if (command=="login")
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
                //you are going to input the name and password here
                cout<<"\n\n\n"
                    <<"Enter Username: ";
                getline(cin, inName);
                cout<<"Enter Password: ";
                getline(cin, inPassword);
                if (inName==name && inPassword==password)
                {
                    cout<<"Login Successful\n" //the '\n' is a character, so that's why I can add it 
                    //and it will automatically output a newline in console, alongside the string
                        <<"Welcome, "
                        <<inName;
		    trip.destinationMenu();
			//Ask user to enter in their name
//	string name;
//	cout << "Enter your name: ";
	cin >> name;

	cout << "Welcome to your TripPlanner, " << name << endl;
	
	//call up menu with available continents to have user to choose destination of choice
//	TripPlanner trip;
//	trip.DestinationMenu();
	
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
		   break;
	   	}
                cout<<"incorrect name or password\n";
            }
         
        }
        cout<<"\n\n\n\n\n"; //give it 5 newlines
    }
    return 1;

	
}
