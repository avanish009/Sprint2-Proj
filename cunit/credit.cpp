#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#define LIMIT 15
using namespace std;

class userCredit{
private:
	char name[LIMIT];
public:
	bool checkCredit(char *);
    void putCredit(char *);
    void display();
};


bool checkCredit(char * uname)
{   
	char name[15];
    fstream fptr;
	fptr.open("bin3.dat", ios::in);
	if(!fptr){
		cerr<<"Error in registration"<<endl;
		exit(0);
	}

	while(fptr.read((char *)&name,sizeof(name))){
		if(strcmp(name,uname)==0){
			cout << "\n\t\t\tThis user name is available!";
			return true;
	      }	
	   }	
    fptr.close();
    return false;

}
