//Written By: Wafik Aboualim
//11/6/2022
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include "map.h";
#include "keyValuePair.h";
using namespace std;
class fileReader
{
public:
    // variable to store all items read in the file
    int itemsRead;
    // a string that has the filePath to read
    string filePath;
    // ifstream to read from the text file.
    ifstream indata;
    // constructor 
    fileReader(string filePath);
    int no_of_entries();
    keyValuePair* writeFileIntoArray(int arrSize);
    void writeArrayIntoFile(keyValuePair arr[], int size);
};


