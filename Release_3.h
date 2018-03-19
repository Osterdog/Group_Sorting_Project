#ifndef RELEASE_3_H
#define RELEASE_3_H


#include "Release_2.h"
#include "ArrayItem.h"


class studentrecord_item : public basic_item
{

public:

	stringitem first_name;
	stringitem middle_name;
	stringitem family_name;
	integer_item student_id;
	stringitem email;
	stringitem nationality;
	dob_item dob;
	biodata_item  bio;

	virtual void enterItemFromKeyboard()
	{
		cout << "Insert first name ." << endl;
		first_name.enterItemFromKeyboard();

		cout << "Insert middle name ." << endl;
		middle_name.enterItemFromKeyboard();

		cout << "Insert family name ." << endl;
		family_name.enterItemFromKeyboard();

		cout << "insert student I.D number" << endl;
		student_id.enterItemFromKeyboard();

		cout << "Enter Nationality" << endl;
		nationality.enterItemFromKeyboard();

		cout << "Enter EMAIL address" << endl;
		email.enterItemFromKeyboard();

		// item filled
		empty = false;

	}

	virtual void enterItemFromRandom()
	{
		//cout << "Insert first name ." << endl;
		first_name.generateRandomName();

		//cout << "Insert middle name ." << endl;
		middle_name.generateRandomName();

		//cout << "Insert family name ." << endl;
		family_name.generateRandomName();

		//cout << "insert student I.D number" << endl;
		student_id.generateRandomItem();

		//cout << "Enter Nationality" << endl;
		nationality.generateRandomNationality();

		//cout << "Enter EMAIL address" << endl;
		//email.generateRandomEmail;

		// item filled
		empty = false;

	}

	virtual void printItemOnScreen()
	{
		if (isEmpty())
			cout << "Item is empty." << endl;
		else
		{
			cout << "first name is ";
			first_name.printItemOnScreen();
			cout << endl;

			cout << "middle name is ";
			middle_name.printItemOnScreen();
			cout << endl;

			cout << "Family name is ";
			family_name.printItemOnScreen();
			cout << endl;

			cout << "Student I.D  is ";
			student_id.printItemOnScreen();
			cout << endl;

			cout << "Nationality  is ";
			nationality.printItemOnScreen();
			cout << endl;

			cout << "EMAIL address  is ";
			email.printItemOnScreen();
			cout << endl;
		}
	}

	virtual void release_3_program()
	{
		//enterItemFromKeyboard();
		enterItemFromRandom();
		printItemOnScreen();

	};

	virtual void generateRandomItem(){ ; }

	virtual bool IsLargerThan(basic_item* other_item, basic_sort_criteria* sort_criteria = NULL) {  return NULL; }

	// add anotehr function: IsEqualTo(...)

	// void generateRandomDOB(){

	// }
	virtual basic_item* allocateNewItem(){ return NULL; }
	virtual void deleteOtherItem(basic_item* item){ ; }
};
#endif /* Release_1_h */