#ifndef RELEASE_2_H
#define RELEASE_2_H

#include "Release_1.h"


class bio_item : public basic_item{
public:
	integer_item age, height, weight;

public:
	bio_item(){ ; }
	~bio_item(){ ; }



	virtual void printItemOnScreen()
	{
		if (isEmpty())
			cout << "Item is empty." << endl;
		else
		{
			cout << "age is ";
			age.printItemOnScreen();
			cout << endl;

			cout << "weight is ";
			weight.printItemOnScreen();
			cout << endl;

			cout << "height is ";
			height.printItemOnScreen();
			cout << endl;
		}
	}

	virtual void enterItemFromKeyboard()
	{
		cout << "Insert age ." << endl;
		age.enterItemFromKeyboard();

		cout << "Insert weight ." << endl;
		weight.enterItemFromKeyboard();

		cout << "Insert height ." << endl;
		height.enterItemFromKeyboard();

		// item filled
		empty = false;
		//empty=( age.isEmpty() || weight.isEmpty() || height.isEmpty() );
	}

	virtual bool  vailidity_check()
	{
		if ((age.getItemVal() > 0) && (weight.getItemVal() > 0) && (height.getItemVal() > 0))
		{
			return true;
		}
		else { return false; }
	}

	virtual void biodata_program()
	{
		enterItemFromKeyboard();
		if (vailidity_check())
		{
			printItemOnScreen();
		}
		else
		{
			cout << "invalid data entry - non-zero, positive integers only" << endl;
			enterItemFromKeyboard();
		}
	}

	virtual void generateRandomBioData()
	{
		age.generateRandomAge();
		weight.generateRandomWeight();
		height.generateRandomHeight();
	}

	virtual void execute_biodata()
	{
		int number_of_student = 7, i;
		
		for (i = 0; i < number_of_student; i++)
		{
			generateRandomBioData();
			if (vailidity_check())
			{
				printItemOnScreen();
			}
			else cout << "invalid data given" << endl;
		}
	}
		
	

		
	//These must be implemented by any derived item	

	//virtual void loadItemFromFile(FILE* fin)=0;

	// add anotehr function: IsEqualTo(...)

	virtual basic_item* allocateNewItem(){ return NULL; }
	virtual void deleteOtherItem(basic_item* item){ ; }

	virtual bool IsLargerThan(basic_item* other_item, basic_sort_criteria* sort_criteria = NULL)
	{
		/*bool result = false;

		// if the other item is "empty" (non allocated) don't do any comparison
		if (other_item == NULL)
			return false;


		// first typecast the other item to confimr it is the same as this;
		bio_item* typecasted_other_item = typecastItem(other_item, this);

		// check that it worked
		if (typecasted_other_item == NULL)
		{
			cout << "Other item is not of type integer_item." << endl;
			return false;
			// items of the wrong type (or null pointers) will be pushed to the end of the list
		}

		// now verify if the other item is larger than the curren
		if (getItemVal() > (typecasted_other_item->getItemVal()))
			result = true;


		// chek if there are sorting options to apply 
		if (sort_criteria != NULL)
		{
			// if sorting is in descending order the result is reversed 
			if (!(sort_criteria->getAscending()))
				result = !result;
		}

		return result;*/ return NULL;
	}

};


#endif /* Release_2_h */