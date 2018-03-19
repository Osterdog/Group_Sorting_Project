#include "sortstring.h"
#include "sort.h"
#include "ArrayItem.h"
#include "iostream"
#include <string>
#include <vector>
//first,middle,last,ID,Country,email,DoB(year,month,day),height,weight)
//array[[f,m,l,id,c,e,dob,bio],[f,m,l,id,c,e,dob,bio]....]
//string,string,string,integer,string,string,int,int

void sort_first(char arr[],int m) {
	int i, j, result;
	char workarray[m];
	for (j = 0;j < m;j++) {
		for (i = 0;i < m;i++) {
			result = strcmp(arr[i][0], arr[i + 1][0]);
			if (result > 0) {
				workarray[i] = arr[i + 1];
				workarray[i + 1] = arr[i];
			}
			else {
				workarray[i] = arr[i];
				workarray[i + 1] = arr[i + 1];
			}
		}
	}
	arr = workarray;
}
void sort_last(char arr[], int m) {
	int i, j, results;
	char workarray[m];
	for (j = 0;j < m;j++) {
		for (i = 0;i < m;i++) {
			result = strcmp(arr[i][2], arr[i + 1][2]);
			if (result > 0) {
				workarray[i] = arr[i + 1];
				workarray[i + 1] = arr[i];
			}
			else {
				workarray[i] = arr[i];
				workarray[i + 1] = arr[i + 1];
			}
		}
	}
	arr = workarray;
}
void sort_country(int arr[], int m) {
	int i, j, results;
	char workarray[m];
	for (j = 0;j < m;j++) {
		for (i = 0;i < m;i++) {
			result = strcmp(arr[i][4], arr[i + 1][4]);
			if (result > 0) {
				workarray[i] = arr[i + 1];
				workarray[i + 1] = arr[i];
			}
			else {
				workarray[i] = arr[i];
				workarray[i + 1] = arr[i + 1];
			}
		}
	}
	arr = workarray;
}// Sort by country
void sort_ID(int arr[], int m) {
	int i, j;
	char workarray[m];
	for (j = 0;j < m;j++) {
		for (i = 0;i < m;i++) {
			if (arr[i][3] > arr[i+1][3]) {
				workarray[i] = arr[i + 1];
				workarray[i + 1] = arr[i];
			}
			else {
				workarray[i] = arr[i];
				workarray[i + 1] = arr[i + 1];
			}
		}
	}
	arr = workarray;
}//sort by ID
void sort_DoB(int arr[], int m) {
	int i, j;
	char workarray[m];
	for (j = 0;j < m;j++) {
		for (i = 0;i < m;i++) {
			if (arr[i][6] > arr[i + 1][6]) {
				workarray[i] = arr[i + 1];
				workarray[i + 1] = arr[i];
			}
			else {
				workarray[i] = arr[i];
				workarray[i + 1] = arr[i + 1];
			}
		}
	}
	arr = workarray;
}//sort by DoB
void sort_height(int arr[], int m) {
	int i, j;
	char workarray[m];
	for (j = 0;j < m;j++) {
		for (i = 0;i < m;i++) {
			if (arr[i][8] > arr[i + 1][8]) {
				workarray[i] = arr[i + 1];
				workarray[i + 1] = arr[i];
			}
			else {
				workarray[i] = arr[i];
				workarray[i + 1] = arr[i + 1];
			}
		}
	}
	arr = workarray;
}//sort by height
void sort_weight(int arr[], int m) { //sort by weight
	int i, j;
	char workarray[m];
	for (j = 0;j < m;j++) {
		for (i = 0;i < m;i++) {
			if (arr[i][9] > arr[i + 1][9]) {
				workarray[i] = arr[i + 1];
				workarray[i + 1] = arr[i];
			}
			else {
				workarray[i] = arr[i];
				workarray[i + 1] = arr[i + 1];
			}
		}
	}
	arr = workarray;
}//sort by weight
void descending(int arr[], m) {			//reverses direction of array. default sort is ascending
	arr[] = !arr[]
}

void combine_string(char email,char address,) {
	strcat(email, "@");
	strcat(email, address);
	puts(email);
}

