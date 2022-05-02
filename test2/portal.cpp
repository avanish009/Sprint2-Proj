#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>
#include <thread>
#include "../header/userdata.h"
#include "../header/userlogin.h"
#include "../header/patient.h"
#include "../header/portal.h"
#include "../header/doctor.h"

using namespace std;

void welcome_screen()
{                                                                             
    cout<<"\n\t\t\t=========================================================";
    cout<<"\n\t\t\t=\t\t\tWELCOME TO\t\t\t=";
    cout<<"\n\t\t\t=\t\tHELPING HAND HOSPITAL\t\t\t=";
    cout<<"\n\t\t\t=========================================================\n";
    cout<<"\n\nPress enter key to continue....";                              
    getchar();
    system("clear");
}

void title()
{                                                                             
    cout<<"\n\t\t\t=========================================================";
    cout<<"\n\t\t\t=\t\tHELPING HAND HOSPITAL\t\t\t=";
    cout<<"\n\t\t\t=========================================================\n";
                                                                                
}

void logPortal()
{
    title();
    int input;
    cout<<"\n\n\n\t\t\t\tPORTAL:";
    cout<<"\n\n\t\t\t\tPress '1' to Register\n\t\t\t\tPress '2' to Login\n\t\t\t\tPress '3' to Forget Password";
    cout<<"\n\t\t\t\tPress '4' to exit Program\n\n\n";
    cout<<"\n\n\t\t\tPress here to continue... ";
    cin>>input;
      if(input == 1)
        {    
            system("clear");
            signUp();
        }

    else if(input == 2)
        {
            system("clear");
            login();
        }
        
   else if(input == 3)
        {   
            system("clear");
            forgotPassword();
        }
     else if(input == 4)
        {   
            system("clear");
            exit(0);
        }    
    else if(input == 8)
        {   
            readCredit();
        }      
    
}

void adminPortal(char * name)
{
    title();
    int input;
    cout<<"\n\n\n\t\t\t\tADMIN PORTAL: "<<name;
    cout<<"\t\t\t";
    timeset();
    cout<<"\n\n\t\t\t\tPress '1' to take Appointment\n\t\t\t\tPress '2' to view  Record";
    cout<<"\n\t\t\t\tPress '3' to Search Record";
    cout<<"\n\t\t\t\tPress '4' to Check Doctor Availabilty";
    cout<<"\n\t\t\t\tPress '5' to Logout\n\n\n";
    cout<<"\n\n\t\t\tPress here to continue... ";
    cin>>input;
      if(input == 1)
        {    
            system("clear");
            addPatient(name);
        }

    else if(input == 2)
        {
            system("clear");
            readPatient(name);
        }
        
   else if(input == 3)
        {   
            system("clear");
            searchPatient(name);
        }
    else if(input == 4)
        {
            system("clear");
            checkDoc(name);
        }
     else if(input == 5)
        {
            system("clear");
            logPortal();
        }           
    
}

void docPortal(char * name,int id)
{
    title();
    int input;
    cout<<"\n\n\n\t\t\t\tDOCTOR PORTAL: "<<name;
    cout<<"\t\t\t";
    timeset();
    yourAppoint(id);
    cout<<"\n\n\t\t\t\tPress '1' to Complete Appointment";
    cout<<"\n\t\t\t\tPress '2' to Change Status";
    cout<<"\n\t\t\t\tPress '3' to Logout\n\n\n";
    cout<<"\n\n\t\t\tPress here to continue... ";
    cin>>input;
      if(input == 1)
        {    
            system("clear");
            complete(name,id);
        }

    else if(input == 2)
        {
            system("clear");
            changeStatus(name,id);;
        }
        
   else if(input == 3)
        {
            system("clear");
            logPortal();
        }     
    
}

void timeset(){
    time_t now = time(0);
    tm *ltm = localtime(&now);

    cout << ltm->tm_mday <<"/" << 1 + ltm->tm_mon<< "/"<<1900 + ltm->tm_year<<endl;
}

