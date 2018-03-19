#ifndef RELEASE_1_H
#define RELEASE_1_H

#include "ArrayItem.h"
#include "sort.h"
#include <string>
#include "time.h"


class names : public basic_item{
protected:

	stringitem first_name;
	stringitem family_name;
public:
    names(){;}
	~names(){ ; };


	virtual void printItemOnScreen(){

		if (isEmpty()){
			cout << "! Blank ! " << endl;
		}
		else{
			cout << "First name is: " << endl;
			first_name.printItemOnScreen();
			cout << "Family name name is: " << endl;
			family_name.printItemOnScreen();
		}
	}

	virtual void enterItemFromKeyboard()
	{
		cout << "Insert first name : " << endl;
		first_name.enterItemFromKeyboard();

		cout << "Insert family naem : " << endl;
		family_name.enterItemFromKeyboard();

		
		// item filled
		empty = false;

	}
	
   virtual bool IsLargerThan(basic_item* other_item, basic_sort_criteria* sort_criteria=NULL){return false;}

   ///////////////////// Gen Rand It ///////////////////////////////

   virtual void generateRandomItem(){

	   first_name.generateRandomName();
	   family_name.generateRandomName();

	   }


   virtual basic_item* allocateNewItem(){ ; }
   virtual void deleteOtherItem(basic_item* item){ ; }
};

class dob_item : public basic_item{
    
protected:
    int day,month,year;    

	public:
    dob_item(){;}
    ~dob_item(){;}

    int getDay(){
        return day;
    }
    int getMonth(){
        return month;
    }
    int getYear(){
        return year;
    }
    void printItemOnScreen(){
        if (isEmpty()){
            cout << "Item isn't there."<<endl;
        }
        else{
            cout << "Date of Birth: " << day << "/" << month <<"/" << year << endl;
        }
    }
    void enterItemFromKeyboard(){
        cout << "Enter day of birth:" << endl;
        cin >> day;
        cout << "Enter month of birth:" << endl;
        cin >> month;
        cout << "Enter year of birth:" << endl;
        cin >> year;
        
        empty = false;
    }
    bool date_check(){
        int max_days;
        
        if (month<1 || month>12){
            cout << "Month range exceeded. Start again." << endl;
            enterItemFromKeyboard();
            return false;
        }
        if (year < 0){
            cout << "This is before Jesus' time. Enter a proper date will you?" << endl;
            enterItemFromKeyboard();
            return false;
        }
        switch (month) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                max_days = 31;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                max_days = 30;
                break;
            case 2:
                if ((year % 4 == 0) || (year % 400 == 0))
                    max_days = 29;
                else if(year % 100 == 0)
                    max_days = 28;
                else
                    max_days = 28;
                break;
            default:
                return false;
        }
        if ((day<1) || (day>max_days)){
            cout << "Day range exceeded. Start again." << endl;
            enterItemFromKeyboard();
            return false;
        }
        else
            return true;
    }
    bool IsLargerThan(basic_item* other_item, basic_sort_criteria* sort_criteria=NULL){
        bool result=false;
        
        // if the other item is "empty" (non allocated) don't do any comparison
        if(other_item==NULL)
            return false;
        
        
        // first typecast the other item to confimr it is the same as this;
        dob_item* typecasted_other_item = typecastItem(other_item, this);
        
        // check that it worked
        if(typecasted_other_item==NULL)
        {
            cout << "Other item is not of type integer_item." << endl;
            return false;
            // items of the wrong type (or null pointers) will be pushed to the end of the list
        }
        
        // now verify if the other item is larger than the curren
        if( getDay() > (typecasted_other_item->getDay()))
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
   // void generateRandomDOB(){
        
   // }
	virtual basic_item* allocateNewItem(){ return NULL; }
	virtual void deleteOtherItem(basic_item* item){ ; }

	virtual void generateRandomItem(){
		int days, months, years;
		days = rand() % (30 + 1 - 1) + 1;
		months = rand() % (12 + 1 - 1) + 1;
		years = rand() % (3000 + 1 - 0) + 0;

		day = days;
		month = months;
		year = years;

		empty = false;
	}
	
};


#endif /* Release_1_h */
