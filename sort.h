#ifndef __SORT_H__
#define __SORT_H__


#include "malloc.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "math.h"

#include "iostream"
#include "fstream"

using namespace std;


void fill_list_from_keyboard(int integer_list[], int tot_items);
void fill_list_random(int integer_list[], int tot_items);
void print_list_to_screen(int integer_list[], int tot_items);

void bubblesort_list(int integer_list[], int tot_items);

//
void mergesort_list(int* integer_list, int tot_items);
void mergesort_list_stackallocation(int* integer_list, int tot_items);
//

void fill_list_from_file(char* filename, bool BinaryNotText, int integer_list[], int* inp_tot_items);
void print_list_to_file(char* filename, bool BinaryNotText, int integer_list[], int tot_items);

void copy_list(int* int_list_source, int* int_list_dest, int tot_items);
bool check_lists_equal(int* int_list_source, int* int_list_dest, int tot_items);

#endif