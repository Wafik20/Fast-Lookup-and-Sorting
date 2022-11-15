//Written By: Wafik Aboualim
//Main Project, Section C
//CS-312 Introduction to Algorithms
//11/6/2022
/*

*/
#include "map.h";
/*
-----------------------------------------------------------------*
 Description: constructor                                        
 initialize the number of buckets and create a list of buckets  
 Pre: None                                                       
 Post: object instance created.                                  
-----------------------------------------------------------------*
*/
map::map(int buckets)
{
	this->BUCKETS = buckets;
	table = new list<keyPointer>[BUCKETS];
}
/*
* -----------------------------------------------------------------*
 Description: hash(int key) take an integer key and hashs the key to a bucket
 initialize the number of buckets and create a list of buckets
 Pre: None
 Post: object instance created.
 -----------------------------------------------------------------*
*/
int map::hash(int key)
{
	return key%BUCKETS;
}
/*
------------------------------------------------------------------*
 Description: inserts an object of type keyPointer in the hashmap
 Pre: An instance of keyValuePair, and an integer corrosponding to its index in keyValuePair array 
 Post: Stores in the hashmap a key and a pointer to its index in the keyValuePair array.
 -----------------------------------------------------------------*
*/
void map::insertItem(keyValuePair pair, int index)
{
	//hash the key to a bucket
	int loc = hash(pair.key);
	//create keyPointer object
	keyPointer curr = keyPointer(pair.key, index);
	// insert item in bucket
	table[loc].push_back(curr);
}
/*
-----------------------------------------------------------------*
 Description: inserts an array of object of type keyValuePair in the hashmap
 Pre: An array of type keyValuePai, and an integer size corrosponding to the size of that array, and an instance of type map with BUCKETS >= size
 Post: map that contains all the keys in the keyValuePair array, and its corrosponding index in the keyValuePair array
 -----------------------------------------------------------------*
*/
void map::insertArray(keyValuePair arr[], int size)
{
	for (int i = 0; i < size; i++) {
		keyValuePair curr_pair = arr[i];
		insertItem(curr_pair, i);
}
}
/*
------------------------------------------------------------------*
 Description: visualize the hashmap
 Pre: None
 Post: printed string that contains all buckets and their corrosponding data.
 -----------------------------------------------------------------*
*/
void map::printMap() {
	for (int i = 0; i < BUCKETS; i++) {
		printf("[%d]", i);
		for (auto x : table[i])
			printf("--> {key= %d, index in keyValuePair arr= %d}", x.key, x.pointer);
		cout << endl;
	}
}
/*
------------------------------------------------------------------*
 Description: A health check function for the hashmap to check how well the hashmap is working
 Pre: an instance of map that has been initialized using insertArray(keyValuePair arr[], int size) 
 Post: a string describing the longest chain in the hashmap and the percentage of non-empty locations in the map
 -----------------------------------------------------------------*
*/
void map::monitor()
{
	//index of bucket with largest linked list
	int max_bucket_index = 0;
	int no_max_elements = 0;
	int non_empty_locations = 0;
	int percentage = 0;
	//iterate over all buckets
	for(int i = 0; i < BUCKETS; i++) {
		int bucket_size = table[i].size();
		if ( bucket_size > no_max_elements) {
			no_max_elements = bucket_size;
			max_bucket_index = i;
		}
		if (bucket_size >= 1) {
			non_empty_locations++;
		}
	}
	//finding percentage of non-empty locations
	percentage = (int) round(((double) non_empty_locations / (double) BUCKETS)*100);
	//print the values
	cout << "----------------------------------------------------------------------";
	printf("\nbucket with the max chain is at index %d and has %d elements         |\n", max_bucket_index, no_max_elements);
	printf("%d%% of locations have 1 or more elements                              |\n", percentage);
	cout << "----------------------------------------------------------------------" << endl;
}
/*
-----------------------------------------------------------------*
 Description: Look-up an item in the hashmap                                       
 Pre: An non-empty instance of map                                                      
 Post: returns the index of the key in the keyValuePair array and a string containing information about the instance of keyPointer
-----------------------------------------------------------------*
*/
int map::lookup(int key)
{
	// hash key to find the bucket which contains the item in the map
	int loc = hash(key);
	// iterate over the bucket items
	for (auto x : table[loc]) {
		if (x.key == key) {
			printf("item found in bucket %d and corrosponds to index %d in the array \n", loc, x.pointer);
			printf("[%d] --> .... --> %d\n", loc, key);
			//return index in the array
			return x.pointer;
		}
	}
	// cannot find item
	cout << "Key not found";
	return -1;
}
