#ifndef __ARRAYITEM_H_
#define __ARRAYITEM_H_

#include "sort.h"
#include <string>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>



static const string names[14] = { "Brian", "James", "James", "Puan", "Billy", "Scott", "Angel" "Osterman", "MacLean", "Short", "Sheng", "Duthie", "MacDougal", "Iliev" };
//static const string last_names[7] = { "Osterman", "MacLean", "Short", "Sheng", "Duthie", "MacDougal", "Iliev" };

////// this is needed to check compatibility between items (and to use a derived-class pointer that is passes as "base class")
template <class Base, class Derived> Derived* typecastItem(Base* basic_ptr, Derived* derivedItem_ptr)
{
	Derived* typecasted_ptr=dynamic_cast <Derived *>(basic_ptr);

	//if(typecasted_ptr==NULL)				
		//printf("\n Error typecasting item: type does not match the expected derived item\n");

	return typecasted_ptr;
}
//////


// suggestion: rename as sortoptions; extend later to include more options
enum biosortoptions{
	sort_age=0, sort_weight, sort_height
};


class basic_sort_criteria{
protected:
	bool ascending;
	//
	biosortoptions sortoption;

public:
	basic_sort_criteria(){ setAscending(true); setSortoption(sort_age); }
	void setAscending(bool value){ascending=value;}
	bool getAscending(){return ascending;}
	//
	void setSortoption(biosortoptions value)
	{
		if(value>=sort_age && value<=sort_height) sortoption=value;
	}
	
	biosortoptions getSortoption(){return sortoption;}

};
//


class basic_item{
protected:
	bool empty;

public:
	basic_item(){empty=true;}
	~basic_item(){;}
	
	bool isEmpty(){return empty;}
	
	//These must be implemented by any derived item	
	virtual void printItemOnScreen()=0;
	virtual void enterItemFromKeyboard()=0;
	//virtual void loadItemFromFile(FILE* fin)=0;
	virtual void generateRandomItem()=0;
	
	virtual bool IsLargerThan(basic_item* other_item, basic_sort_criteria* sort_criteria=NULL)=0;

	// add anotehr function: IsEqualTo(...)

	virtual basic_item* allocateNewItem()=0;
	virtual void deleteOtherItem(basic_item* item) = 0;
};



//
class integer_item: public basic_item{
protected:
	int item_value;

public:
	integer_item(){;}
	~integer_item(){;}

	int getItemVal(){return item_value;}
	
	virtual void printItemOnScreen()
	{
		if(isEmpty())
			cout << "Item is empty." << endl;
		else
			cout << "Item value is " << item_value << " . " << endl;
	}

	virtual void enterItemFromKeyboard()
	{
		cout << "Insert element then hit enter." << endl;
		cin >> item_value;
		cout << endl;
		
		// item filled
		empty=false;
	}

	virtual void generateRandomItem()
	{
		int item;
		int max_rand_val = 1000;

		item=rand();
		item = item % (max_rand_val+1);

		// turn to negative 30% of the time
		if( (rand()%10) >=7 )
			item=(-1)*item;

		item_value=item;
		// item filled
		empty=false;
		
	}
	virtual void generateRandomAge()
	{
		int item;
		int max_rand_val = 108;

		item = rand();
		item = item % (max_rand_val + 1);
		item_value = item;
		// item filled
		empty = false;
	};
	virtual void generateRandomWeight()
	{
		int item;
		int max_rand_val = 200;

		item = rand();
		item = item % (max_rand_val + 1);
		item_value = item;
		// item filled
		empty = false;
	};
	virtual void generateRandomHeight()
	{
		int item;
		int max_rand_val = 220;

		item = rand();
		item = item % (max_rand_val + 1);
		item_value = item;
		// item filled
		empty = false;
	};

	/*virtual void generateRandomDay()
	{
		//days = rand() % (30 + 1 - 1) + 1;
		int item;
		int max_rand_val = 31;

		item = rand();
		item = item % (max_rand_val + 1);
		item_value = item;
		// item filled
		empty = false;

			}
	//virtual void generateRandomMonth()
	{
		//days = rand() % (30 + 1 - 1) + 1;
		int item;
		int max_rand_val = 12;

		item = rand();
		item = item % (max_rand_val + 1);
		item_value = item;
		// item filled
		empty = false;

	}
	//virtual void generateRandomYear()
	{
		//days = rand() % (30 + 1 - 1) + 1;
		int item;
		int max_rand_val = 2016;

		item = rand();
		item = item % (max_rand_val + 1);
		item_value = item;
		// item filled
		empty = false;

	}*/
	//virtual void loadItemFromFile(FILE* fin);
	
	virtual bool IsLargerThan(basic_item* other_item, basic_sort_criteria* sort_criteria = NULL)
	{
		bool result = false;

		// if the other item is "empty" (non allocated) don't do any comparison
		if (other_item == NULL)
			return false;
	
		
		// first typecast the other item to confimr it is the same as this;
		integer_item* typecasted_other_item = typecastItem(other_item, this);
		
		// check that it worked
		if(typecasted_other_item==NULL)
		{
			cout << "Other item is not of type integer_item." << endl;
			return false;
			// items of the wrong type (or null pointers) will be pushed to the end of the list
		}

		// now verify if the other item is larger than the curren
		if( getItemVal() > (typecasted_other_item->getItemVal()) )
			result=true;


		// chek if there are sorting options to apply 
		if(sort_criteria!=NULL)
		{
			// if sorting is in descending order the result is reversed 
			if( !( sort_criteria->getAscending() ) )
				result=!result;
		}

		return result;
	}

	virtual basic_item* allocateNewItem()
	{
		integer_item* result = new integer_item;
		return result;
	}

	virtual void deleteOtherItem(basic_item* item)
	{
		if(item!=NULL)
		{
			// first typecast the other item to confimr it is the same as this;
			integer_item* typecasted_other_item = typecastItem(item, this);

			// check that it worked
			if(typecasted_other_item==NULL)
			{
				// items of the wrong type 
				cout << "Other item is not of type integer_item." << endl;				
			}
			else
				delete typecasted_other_item;
		}
	}

};



/////////////////////////


class biodata_item: public basic_item{
public:
	integer_item age;
	integer_item weight;
	integer_item height;

public:
	biodata_item(){;}
	~biodata_item(){;}

	
	virtual void printItemOnScreen()
	{
		if(isEmpty())
			cout << "Item is empty." << endl;
		else
		{
			cout << "age is " ;
			age.printItemOnScreen();
			cout << endl;

			cout << "weight is " ;
			weight.printItemOnScreen();
			cout << endl;

			cout << "height is " ;
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
		empty=false;
		//empty=( age.isEmpty() || weight.isEmpty() || height.isEmpty() );
	}

	virtual void generateRandomItem()
	{
		age.generateRandomItem(); 
		
		weight.generateRandomItem();

		height.generateRandomItem();

		// item filled
		empty= false;
		//empty=( age.isEmpty() || weight.isEmpty() || height.isEmpty() );
		
	}
	
	
	virtual bool IsLargerThan(basic_item* other_item, basic_sort_criteria* sort_criteria=NULL)
	{
		bool result=false;
		
		// if the other item is "empty" (non allocated) don't do any comparison
		if(other_item==NULL)
			return false;

		
		// first typecast the other item to confimr it is the same as this;
		biodata_item* typecasted_other_item = typecastItem(other_item, this);
		
		// check that it worked
		if(typecasted_other_item==NULL)
		{
			cout << "Other item is not of type integer_item." << endl;
			return false;
			// items of the wrong type (or null pointers) will be pushed to the end of the list
		}

		// default criteria, assume we sort by age
		biosortoptions sortype=sort_age;
		if( sort_criteria!=NULL )
			sortype=sort_criteria->getSortoption();


		switch (sortype){
		case sort_age:			
			result=age.IsLargerThan( &(typecasted_other_item->age), sort_criteria );
			break;
		case sort_weight:
			result=weight.IsLargerThan( &(typecasted_other_item->weight), sort_criteria );
			break;
		case sort_height:
			result=height.IsLargerThan( &(typecasted_other_item->height), sort_criteria );
			break;
		default:
			;
		}
		
		

		return result;
	}


	virtual basic_item* allocateNewItem()
	{
		biodata_item* result = new biodata_item;
		return result;
	}

	virtual void deleteOtherItem(basic_item* item)
	{
		if(item!=NULL)
		{
			// first typecast the other item to confimr it is the same as this;
			biodata_item* typecasted_other_item = typecastItem(item, this);

			// check that it worked
			if(typecasted_other_item==NULL)
			{
				// items of the wrong type 
				cout << "Other item is not of type integer_item." << endl;				
			}
			else
				delete typecasted_other_item;
		}
	}

};


//////////////////////////

//
class cplx_item : public basic_item{
protected:
	int real_part, im_part;
	double modulo;
public:
	cplx_item(){ real_part = 0; im_part=0; }
	~cplx_item(){ ; }

	int getRealpart(){ return real_part; }
	int getImgpart(){ return im_part; }
	double getModulo(){ return modulo; }
	double computeModulo(){ return sqrt((im_part*im_part) + (real_part*real_part));}
	virtual void printItemOnScreen()
	{
		if (isEmpty())
			cout << "Item is empty." << endl;
		else
		{
			cout << "Item real part is " << getRealpart() << " . " << endl;
			cout << "Item img part is " << getImgpart() << " . " << endl;
			cout << "Item modulo is " << getModulo() << " . " << endl;
		}
		
		//this->real_part;
	}

	virtual void enterItemFromKeyboard()
	{
		// item filled
		
		cout << "Insert real part for this element then hit enter." << endl;
		cin >> real_part;
		cout << endl;

		cout << "Insert imnaginary part for this element then hit enter." << endl;
		cin >> im_part;
		cout << endl;

		modulo = computeModulo();

		// item filled
		empty = false;


	}

	virtual void generateRandomItem()
	{
		int item;
		int max_rand_val = 1000;

		item = rand();
		item = item % (max_rand_val + 1);

		// turn to negative 30% of the time
		if ((rand() % 10) >= 7)
			item = (-1)*item;

		real_part = item;
		
		item = rand();
		item = item % (max_rand_val + 1);

		// turn to negative 30% of the time
		if ((rand() % 10) >= 7)
			item = (-1)*item;
		
		im_part = item;

		modulo = computeModulo();

		// item filled
		empty = false;

	}

	//virtual void loadItemFromFile(FILE* fin);

	virtual bool IsLargerThan(basic_item* other_item, basic_sort_criteria* sort_criteria = NULL)
	{
		bool result = false;

		// if the other item is "empty" (non allocated) don't do any comparison
		if (other_item == NULL)
			return false;
		
		//this->real_part
		//this->im_part;

		// first typecast the other item to confimr it is the same as this;
		cplx_item* typecasted_other_item = typecastItem(other_item, this);

		// check that it worked
		if (typecasted_other_item != NULL)
		{
			// now verify if the other item is larger than the curren
			if (getModulo() > (typecasted_other_item->getModulo()))
				result = true;
		}
		else
		{
			// check if it is of integer type;
			integer_item* empty_item=NULL;
			integer_item* typecasted_other_item = typecastItem(other_item, empty_item);
			
			// check that it worked
			if (typecasted_other_item == NULL)
			{
				cout << "Other item is not of type cplx_item or Int_item." << endl;
				return false;
				// items of the wrong type (or null pointers) will be pushed to the end of the list
			}

			if ( getModulo() > ( abs(typecasted_other_item->getItemVal()) ) )
				result = true;
		}
		

		// chek if there are sorting options to apply 
		if (sort_criteria != NULL)
		{
			// if sorting is in descending order the result is reversed 
			if (!(sort_criteria->getAscending()))
				result = !result;
		}

		return result;
	}



	virtual basic_item* allocateNewItem()
	{
		cplx_item* result = new cplx_item;
		return result;
	}

	virtual void deleteOtherItem(basic_item* item)
	{
		if(item!=NULL)
		{
			// first typecast the other item to confimr it is the same as this;
			cplx_item* typecasted_other_item = typecastItem(item, this);

			// check that it worked
			if(typecasted_other_item==NULL)
			{
				// items of the wrong type 
				cout << "Other item is not of type integer_item." << endl;				
			}
			else
				delete typecasted_other_item;
		}
	}

};

//////////////

class nameitem : public basic_item{
	;
public:
	virtual void printItemOnScreen(){ ; }
	virtual void enterItemFromKeyboard(){ ; }
	virtual void generateRandomItem() { ; }
	virtual bool IsLargerThan(basic_item* other_item, basic_sort_criteria* sort_criteria = NULL)
	{
		return false;
	}

	virtual basic_item* allocateNewItem() { return NULL; }

	virtual void deleteOtherItem(basic_item* item) { ; }


};

//////   string item ----------------------------------------------------- //////////
//////   string item ----------------------------------------------------- //////////

class stringitem : public basic_item{
	private:
		string stringobj;

		//srand((unsigned int)(time(NULL)));
		
	public:
		stringitem(){ ; }
		~stringitem(){ ; }
		
		virtual void printItemOnScreen()
		{
			cout << "You entered " << stringobj << "." << endl;
		}
		virtual void enterItemFromKeyboard()
		{
			cout << "Enter string " << endl;
			//getline(cin, stringobj);
			cin >> stringobj;

		}
		virtual void generateRandomName() { 
			

			string name;
			int length = 14, rand_element;
			rand_element = rand() % length;
			//rand_element2 = rand() % length;

			name  = names[rand_element];
			//familyname = last_names[rand_element2];

			empty = false;
		}

		//////// GENERATE RANDOM EMAIL ADDRESS \\\\\\\\\\\\\\\\\\

		//virtual void generateRandomEmail()

		//////// GENERATE RANDOM NATIONALITY \\\\\\\\\\\\\\\\\\

		virtual void generateRandomNationality(){ 
			int random_integer; 
			

			random_integer = rand() % 6;

				switch (random_integer)
			{
				default: stringobj = "Un-Specified";
				case 1: stringobj = "European";
					break;
				case 2: stringobj = "North American";
					break;
				case 3: stringobj = "Asian";
					break;
				case 4: stringobj = "Polynesian";
					break;
				case 5: stringobj = "South American";
					break;
				case 6: stringobj = "Russian";
					break;
			}

		}
		virtual void generateRandomItem(){ ; }
		
		virtual bool IsLargerThan(basic_item* other_item, basic_sort_criteria* sort_criteria = NULL) { return false; }
		
		virtual basic_item* allocateNewItem() { return NULL; }

		virtual void deleteOtherItem(basic_item* item) { ; }
		
};
//////////////


#endif