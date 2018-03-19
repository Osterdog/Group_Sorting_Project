
#include "test_inherit.h"


void printobject(parentclass* objptr)
{
	objptr->printval();
}


parentclass* allocateandreturn()
{
	parentclass* testparent_ptr = new otherchildclass; 
	return testparent_ptr;
	
	//otherchildclass child;
	//return &(child);
}


void yetmoremoremain()
{
	int myint;
	//parentclass parentobject;
	parentclass* objptr2 = new childclass;


	childclass childobject;
	
	otherchildclass otherchildobject;
	//parentobject.printval();

	childobject.printval();
	
	//otherchildobject.printval();
	
	parentclass* objptr = &childobject;
	
	printobject(objptr);

	{
		char temp;
		cout << endl << "hit ENTER " << endl;
		temp = getchar();

		cout << endl << "hit ENTER to finish" << endl;
		temp = getchar();
	}
}


