#ifndef portal_h
#define portal_h




class info{
protected:
	char firstName[15];
    char lastName[15];
    int age;

};

void welcome_screen();
void title();
void logPortal();
void adminPortal(char *);
void docPortal(char * ,int);
void timeset();


#endif
