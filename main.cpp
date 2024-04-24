//Written By: Wafik Aboualim
//11/6/2022
/*
Description: This project takes a file of 6-digit integers, unsorted, and stores them in an array of key-value
pairs where each key has a value of 10*key. We implement a hash-map with chaining to store the keys and values.
However, since values might get very large, we save memory resources by only storing a key and a corrosponding
index in the hash-map. We also implement a radix-sort that sorts the array of key-value pairs by key and outputs
a file of sorted keys in the same format as the input file. The hash-map supports the insert and look-up, and delete
opertions, and also a monitor function that calculates the number of empty locations in the hash-map, and the 
longest chain. The project is divided into 4 classes: 1-fileReader 2-keyValuePair 3-radixSort 4-map.

fileReader:
    This class is Initialized by a string corrosponding to the location of the text file containing the integers. This class 
    is responsible for specifying the number of integers contained within the file. It is also responsible for writing the file 
    in an array of objects, and vice-versa creating a file and writing the array of object in the text file.

keyValuePair:
    This class is a simple structure to hold the key and the values of the integers of the file. 

radixSort:
    This class is responsible for the sorting process. It uses the radix sort algorithm and counting sort as a sub-routine.
    We initialize an instance of that object using an integer ("size") representing the size of the array to be sorted.

map:
    This class is a simple implementation of a hashmap that supports the insert, lookup operations. We initialize an instance
    of the map object using a number (buckets) representing the size of an array of buckets. Each bucket is List<> of type
    keyPointer which is a simple struc to hold the key and an index corrosponding to the key's index in the keyValuePair array.
    This class has a function to visualize the hash-map and a health check function to make sure the hash-map is working as expected.
*/
#include <iostream>
#include "map.h";
#include "keyValuePair.h";
#include "fileReader.h";
#include "radixSort.h";
using namespace std;
void printArrOfPairs(keyValuePair arr[], int size);
void menu();
int main()
{
    /*
    NOTE: Before running the project change the value of filePath and set it equal to the path for the text file of
    of integers.
    */
    //input of user
    int choice;
    // the file path for keys.txt
    /*
    Change path here!!!!!!!!
    */
    const string filePath = "C:\\Users\\Wafik\\Downloads\\keys.txt";
    //instantiaiting a fileReader instance
    /*
    CHOOSE PATH FILE FOR "keys.txt", fileReader file = fileReader("C:\\...\\keys.txt" --> the file path for keys.txt ) 
    */
    fileReader file = fileReader(filePath);
    //finding how many 6-digit numbers in the file
    const int size = file.no_of_entries();
    cout << "reading file..." << endl;
    cout << "initializing array..." << endl;
    //initializing the array and the map
    keyValuePair* arr = file.writeFileIntoArray(size);
    map umap = map(size);
    //insert the array in the map
    umap.insertArray(arr, size);
    while (true) {
        // print the menu
        menu();
        // take input from user
        cout << "\nenter choice (-1 to exit)" << endl;
        cin >> choice;
        if (choice == -1) {
            break;
        }
        // checking for invalid input
        if (cin.fail() || choice < 0 || choice>6) {
            cout << "invalid input" << endl;
            cin.clear();
            cin.ignore(256, '\n');
        }
        else if (choice == 1) {
            printArrOfPairs(arr, size);
        }
        else if (choice == 2) {
            cout << "sorting array..." << endl;
            radixSort sort = radixSort(6000);
            sort.radixsort(arr);
            printArrOfPairs(arr, size);
            file.writeArrayIntoFile(arr, size);
        }
        else if (choice == 3) {
            int key;
            while (true) {
                cout << "enter key (-2 to exit)" << endl;
                cin >> key;
                if (key == -2) {
                    break;
                }
                cout << "\n================================================================================" << endl;
                int val_index = umap.lookup(key);
                if (val_index == -1) {
                    cin.clear();
                    cin.ignore(256, '\n');
                }
                else {
                    printf("val = arr[%d] = %d", val_index, arr[val_index].value);
                }
                cout << "\n================================================================================\n" << endl;
            }
        }
        else if (choice == 4) {
            umap.printMap();
        }
        else if (choice == 5) {
            umap.monitor();
        }
    }
    //delete array
    delete[] arr;
}
/*
------------------------------------------------------------------*
 Description: a function to print the array of type keyValuePair
 Pre: an array of keyValuePair
 Post: A string corrosponding to a keyValuePair array
 -----------------------------------------------------------------*
*/
void printArrOfPairs(keyValuePair arr[], int size) {
    for (int i = 0; i < size; i++)
    {
        if (i % 10 == 0)
        {
            cout << endl;
        }
        printf("{%d , %d}", arr[i].key, arr[i].value);
    }
}
/*
------------------------------------------------------------------*
 Description: display a menu of options
 Pre: none
 Post: a string to show a menu of options
 -----------------------------------------------------------------*
*/
void menu() {
    cout << "" << endl;
    cout << "1-print key-value pairs array\n2-sort array by key and output in a file\n3-look up a value\n4-print the hashmap\n5-hashmap analytics" << endl;
}
