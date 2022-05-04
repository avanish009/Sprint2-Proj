#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

bool checkName(char * name){
    
    for(unsigned int i=0;i<(unsigned )strlen(name);i++){
      if(int(name[i])<65){

      cout<<"\n\t\t\t\tEnter your correct Name!";
      return false;
    }
  }
    cout << "\n\t\t\tFirst name is valid!";
    return true;

  }

