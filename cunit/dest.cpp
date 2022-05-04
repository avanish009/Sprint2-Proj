#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

bool destinationMenu(int input)
{
      if(input == 1)
        {    
            cout<<"\n\t\t\t\tDelhi";
            return true;
        }

    else if(input == 2)
        {
           cout<<"\n\t\t\t\tGoa";
            return true;
        }
        
   else if(input == 3)
        {   
            cout<<"\n\t\t\t\tKarnataka";
            return true;
        }
     else if(input == 4)
        {   
            cout<<"\n\t\t\t\tMaharashtra";
            return true;
        }    
   
     else
        {   
            cout<<"\n\t\t\tInvalid Input Try Again!";
            return false;
        }       
    
}