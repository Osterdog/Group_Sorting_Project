#include "sort.h"
#include "msec_timer.h"

#include "generalArray.h"
#include "arrayItem.h"

#include "test_inherit.h"

#include "generalArrayWithTemplate.h"

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


void more_old_main()
{
	
	integer_item myint;

	myint.generateRandomItem();
	myint.printItemOnScreen();

	
	cplx_item mycmplx;

	mycmplx.generateRandomItem();
	mycmplx.printItemOnScreen();

	cplx_item mycmplx2;

	mycmplx2.generateRandomItem();
	mycmplx2.printItemOnScreen();

	bool result = mycmplx.IsLargerThan(&mycmplx2);
	if (result)
		cout << "item 1 larger than 2" << endl;
	else
		cout << "item 2 larger than 1" << endl;



	items_array<integer_item> testarray;

	//items_array<cplx_item> testarray;

	testarray.allocateArray(10);
	testarray.fillRandomValueArray();
	testarray.printArrayOnScreen();


	otherchildclass testchild;
	
	double myvar;

	//integer_item myint2;

	

	


	//parentclass testparent;

	//parentclass* testparent_ptr = new otherchildclass;

	//parentclass* testparent_ptr = allocateandreturn();
	//
	parentclass* testchild_ptr = new otherchildclass;

	otherchildclass* tobedeleted = (otherchildclass*)(testchild_ptr);

	delete(tobedeleted);



	//printobject(testparent_ptr);

	//childclass testchild;

	//otherchildclass testotherchild;

	//testparent.printval();

	//testchild.printval();

	//testotherchild.printval();
	

	//printobject(&testparent);

	//printobject(&testchild);

	//printobject(&testotherchild);


	{
		char temp;
		cout << endl << "hit ENTER " << endl;
		temp = getchar();

		cout << endl << "hit ENTER to finish" << endl;
		temp = getchar();
	}
}



void testmain()
{
	int tot_items;
	int_array test_array;

	basic_sort_criteria sortcrit;
	sortcrit.setAscending(false);

	cout << "Insert tot num of elements (at least 2 )." << endl;
	cin >> tot_items;
	cout << endl;
	
	if(tot_items<2)
		tot_items=2;

	// allocate array
	test_array.allocateArray(tot_items);
	
	// fill with random numbers
	cout << "Fill with random values"<< endl;
	test_array.fillRandomValueArray();

	// print to screen
	test_array.printArrayOnScreen();
	cout << endl;

	// now sort
	cout << "perform sorting "<< endl;
	//test_array.bubblesort();
	test_array.bubblesort(&sortcrit);



	// print to screen again
	cout << "Sorted array"<< endl;
	test_array.printArrayOnScreen();



	{
		char temp;
		cout << endl << "hit ENTER " << endl;
		temp=getchar();
		
		cout << endl << "hit ENTER to finish" << endl;
		temp=getchar();
	} 

}