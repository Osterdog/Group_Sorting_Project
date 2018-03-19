#ifndef BASIC_READ_FROM_FILE_H
#define BASIC_READ_FROM_FILE_H

#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <sstream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;

class basic_basic_file_read{
public:

	string your_filename;
	virtual void readFromFile()
	{


		string line;
		ifstream myfile;

		myfile.open(your_filename.c_str());

		if (myfile.is_open())

		while (getline(myfile, line))
		{

			cout << line << '\n';

		}


		else
		{
			cout << "Unable to open file";
		}




	}

	virtual void EnterFileName()
	{

		cout << "Enter Filename including extension," << endl;
		cout << "for e.g \"example.txt\" : " << endl;
		cin >> your_filename;
	}

	///////////////////// main executable function ///////////////////////////
	virtual void execute_1()
	{
		EnterFileName();
		cout << "text from file is shown between dashed lines" << endl;
		cout << "======================================================" << endl;
		readFromFile();
		cout << "======================================================" << endl;
		getch();

	}


	virtual void extract_word_by_word()
	{
		StrArray[];

		ifstream file;
		file.open(your_filename.c_str());
		if (!file.is_open()) return;

		string word;
		while (file >> word)
		{
			cout << word << '\n';
		}




	}

};

#endif


