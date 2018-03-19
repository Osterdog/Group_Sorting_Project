#ifndef __TESTINHERIT_H_
#define __TESTINHERIT_H_

#include "sort.h"

class parentclass{
protected:
	int intval;
public:
	parentclass(){ intval = 0; }
	virtual void printval() = 0;	
	
};


class childclass : public parentclass{
protected:
	float floatval;
public:
	childclass(){ floatval = 0.5; intval = 2; }
	
	virtual void printval()
	{
		cout << "This is the child print function" << endl;
		cout << "intval is: ";
		cout << intval << endl;
		cout << "floatval is: ";
		cout << floatval << endl;
	}
	
};


class otherchildclass : public parentclass{
protected:
	char letter;
public:
	otherchildclass(){ letter = 'A'; intval = -2; }
	virtual void printval()
	{
		cout << "This is the other child print function" << endl;
		cout << "intval is: ";
		cout << intval << endl;
		cout << "letter is: ";
		cout << letter << endl;

	}
};


#endif
