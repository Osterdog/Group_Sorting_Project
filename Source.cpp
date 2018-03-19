#include <sstream>
#include <cstdio>
#include <iomanip>
#include "Release_3.h"
#include <string>
#include <iostream>     // std::cout
#include <fstream>      // std::ifstream

using namespace std;

/*stringstream templine(firstline);

sstring passfail;
float floatvalue1;
std::string timestr;
std::string namestr;
float floatvalue2;

//  split to two lines for readability
templine >> std::skipws; // no need to worry about whitespaces
templine >> passfail >> timestr >> floatvalue1 >> namestr >> floatvalue2;
*/

int main()
{
	ifstream myfile;
	myfile.open("../student_info.txt", ifstream::in);

	if (!(myfile.is_open()))
	{
		cout << "Error Opening File";
		exit(0);
	}

	string firstline;


	while (myfile.good())
	{
		getline(myfile, firstline);
		cout << "\n" << firstline << "\n";
		getchar();
	}

	myfile.close();
	//system("PAUSE");
	//cin.get();

	return 0;

}