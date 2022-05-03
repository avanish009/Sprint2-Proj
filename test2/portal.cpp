#include <iostream>
#include <string>
#include <string>
#include <vector>
#include <math.h>
#include <TripPlanner.h>
#include <Airline.h>
#include <Hotel.h>
#include <portal.h>

using namespace std;

using namespace std;

void welcome_screen()
{                                                                             
    cout<<"\n\t\t\t=========================================================";
    cout<<"\n\t\t\t=\t\t\tWELCOME TO\t\t\t=";
    cout<<"\n\t\t\t=\t\tTrip Planner\t\t\t=";
    cout<<"\n\t\t\t=========================================================\n";
    cout<<"\n\nPress enter key to continue....";                              
    getchar();
    system("clear");
}

void title()
{                                                                             
    cout<<"\n\t\t\t=========================================================";
    cout<<"\n\t\t\t=\t\tKeep It Simple\t\t\t=";
    cout<<"\n\t\t\t=========================================================\n";
                                                                                
}

void logPortal()
{
    title();
    int input;
    cout<<"\n\n\n\t\t\t\tPORTAL:";
    cout<<"\n\n\t\t\t\tPress '1' to Register\n\t\t\t\tPress '2' to Login";
    cout<<"\n\t\t\t\tPress '3' to exit Program\n\n\n";
    cout<<"\n\n\t\t\tPress here to continue... ";
    cin>>input;
      if(input == 1)
        {    
            system("clear");
            //signUp();
        }

    else if(input == 2)
        {
            system("clear");
            //login();
        }
        
   else if(input == 3)
        {   
            system("clear");
	    exit(0);
           
        } 
    
}





void timeset(){
    time_t now = time(0);
    tm *ltm = localtime(&now);

    cout << ltm->tm_mday <<"/" << 1 + ltm->tm_mon<< "/"<<1900 + ltm->tm_year<<endl;
}

