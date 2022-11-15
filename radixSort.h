//Written By: Wafik Aboualim
//Main Project, Section C
//CS-312 Introduction to Algorithms
//11/6/2022
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include "keyValuePair.h";
class radixSort
{
public:
	// a variable to store the size of array to be sorted
	int sizeArr;
	// constructor
	radixSort();
	radixSort(int sizeArr);
	int getMax(keyValuePair pairArr[]);
	void countSort(keyValuePair pairArr[], int exp);
	void radixsort(keyValuePair pairArr[]);
};



