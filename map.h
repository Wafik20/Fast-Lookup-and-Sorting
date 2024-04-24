//Written By: Wafik Aboualim
//11/6/2022
#pragma once
#include <iostream>
#include <iterator>
#include <list>
#include "keyValuePair.h"
using namespace std;
// struct to store a key and a pointer in the array in the hashmap
struct keyPointer
{
	int key;
	int pointer;
	/*
	Description: instantiate an object of type keyPointer
	contains a key and its corrosponding index in a keyValuePair array
	Pre: None
	Post: object instance created.
	*/
	keyPointer(int key, int pointer) {
		this->key = key;
		this->pointer = pointer;
	}
};
class map
{
public:
	// no of buckets
	int BUCKETS;
	// table to store the object keyPointer which contains a key and pointer to its value in the array
	list<keyPointer> *table;
	// constructor
	map(int buckets);
	// hashfunction
	int hash(int key);
	// insert Item in the hashmap
	void insertItem(keyValuePair x, int index);
	// delete item in the hashmap
	void deleteItem(int key);
	// insert an array of keyValuePairs in the hashmap
	void insertArray(keyValuePair arr[], int size);
	// visualize the map
	void printMap();
	// monitor function
	void monitor();
	int lookup(int key);

};

