//
//  Release_1.h
//  EE40GA_Sort
//
//  Created by Vhaanzeit on 07/11/2016.
//  Copyright © 2016 Vhaanzeit. All rights reserved.
//
#ifndef Release_1_h
#define Release_1_h

#include "ArrayItem.h"
#include "time.h"
#include <string>

static const string first_names[7] = {"Brian","James","James","Puan","Billy","Scott","Angel"};
static const string last_names[7] = {"Osterman","MacLean","Short","Sheng","Duthie","MacDougal","Iliev"};


class First_Names : public basic_item{
protected:
    string first_name,last_name;
public:
    First_Names(){;}
    ~First_Names(){;}
    virtual void printItemOnScreen(){
        if (isEmpty()){
            cout << "Nothing is here." << endl;
        }
        else{
            cout << "First name: " << first_name << endl;
            cout << "Last name: " << last_name << endl;
        }
    }
    virtual void enterItemFromKeyboard(){
        
        cout << "Please enter your first name: " << endl;
        cin >> first_name;
        cout << "Please enter your last name: " << endl;
        cin >> last_name;
        
        empty = false;
    }
    virtual void name_check(){;}
    virtual bool IsLargerThan(basic_item* other_item, basic_sort_criteria* sort_criteria=NULL){return false;}
    
    virtual void generateRandomItem(){
        int length=7,rand_element,rand_element2;
        
        rand_element = rand()%length;
        rand_element2 = rand()%length;
        
        first_name = first_names[rand_element];
        last_name = last_names[rand_element2];
        
        empty = false;
    }
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
    virtual void printItemOnScreen(){
        if (isEmpty()){
            cout << "Item isn't there."<<endl;
        }
        else{
            cout << "Date of Birth: " << day << "/" << month <<"/" << year << endl;
        }
    }
    virtual void enterItemFromKeyboard(){
        cout << "Enter day of birth:" << endl;
        cin >> day;
        cout << "Enter month of birth:" << endl;
        cin >> month;
        cout << "Enter year of birth:" << endl;
        cin >> year;
        
        empty = false;
    }
    virtual bool date_check(){
        int max_days;
        
        if (month<1 || month>12){
            cout << "Month range exceeded. Start again." << endl;
            enterItemFromKeyboard();
            return false;
        }
        if (year < 0){
            cout << "You're in BC. Enter a proper date will you?" << endl;
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
    virtual bool IsLargerThan(basic_item* other_item, basic_sort_criteria* sort_criteria=NULL){
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

        // now verify if the other item is larger than the current
        if( getYear() > (typecasted_other_item->getYear())){
            result=true;
        }
        else{
            if(getMonth() > (typecasted_other_item->getMonth()))
                result = true;
            else{
               if(getDay() > (typecasted_other_item->getDay()))
                result = true;
                else
                    return false;
            }
        }
        // chek if there are sorting options to apply
        if(sort_criteria!=NULL)
        {
            // if sorting is in descending order the result is reversed
            if( !( sort_criteria->getAscending() ) )
                result=!result;
        }
        
        return result;
    }
    virtual void generateRandomItem(){
        int days,months,years;
        days = rand()%(30+1-1)+1;
        months = rand()%(12+1-1)+1;
        years = rand()%(3000+1-0)+0;
        
        day = days;
        month = months;
        year = years;
        
        empty = false;
    }
};
#endif /* Release_1_h */
