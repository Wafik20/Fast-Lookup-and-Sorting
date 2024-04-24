//Written By: Wafik Aboualim
//11/6/2022
#include "fileReader.h"

/*
------------------------------------------------------------------*
 Description: constructor of the fileReader object that contains a file path the number of items read in the file (initialized to 0)
 Pre: A string filePath corrosponding to text file that contains integers in the same format as "keys.txt"
 Post: An instance of the object
 -----------------------------------------------------------------*
*/
fileReader::fileReader(string filePath)
{
    string path = filePath;
    // setting the filePath
    this->filePath = filePath;
    // initializing itemsRead = 0
    itemsRead = 0;
    // cannot open file
    if (!indata)
    {
        cout << "Cannot Open File";
        exit(1);
    }
    else
    // file can be opened
    {
        indata.open(filePath);
        cout << "File Opened" << endl;
    }
}
/*
------------------------------------------------------------------*
 Description: find the number of entries in a text file
 Pre: A text file in the same format as "keys.txt"
 Post: An integer that corrosponds to the number of integers in the text file
 -----------------------------------------------------------------*
*/
int fileReader::no_of_entries()
{
    // set low = 0
    long low = 0L;
    // seek end of file
    indata.seekg(0L, ios::end);
    // divide the total number of bytes in the file by 7 to get the number integers - 1 (each integer is 6 digits + \n = 7 bytes)
    long high = indata.tellg() / 7L;
    // return the number of integers in the file
    return high - low + 1;
    indata.close();
}
/*
------------------------------------------------------------------*
 Description: Write the data of a text file in an array of type keyValuePair
 Pre: An instance of fileReader that mappes to a text file that has the same format such as "keys.txt"
 Post: An array of type keyValuePair
 -----------------------------------------------------------------*
*/
keyValuePair* fileReader::writeFileIntoArray(int arrSize) {
    // seek begin of the file
    indata.seekg(0);
    keyValuePair* arr{ new keyValuePair[arrSize]{} };
    while (!indata.eof())
    {
        // initialize placeholder for current number
        int curr;
        // setting the placeholder equal to the current number
        indata >> curr;
        //initialize instance of keyValuePair
        // putting the number in the array and incrementing the count of numbers read
        arr[itemsRead++].setValue(curr);
    }
    printf("Items read = %d \n", itemsRead);
    indata.close();
    return arr;
}
/*
------------------------------------------------------------------*
 Description: write an array of type keyValuePair and output a text file
 Pre: An array of type keyValuePair that has size = size 
 Post: a string that corrosponds to the sorted array and a file in the directory C://..../output.txt that contains sorted keys
 -----------------------------------------------------------------*
*/
void fileReader::writeArrayIntoFile(keyValuePair arr[], int size)
{
    string output_path = "output.txt";
    ofstream MyFile(output_path);
    for (int i = 0; i < size-1; i++) {
        MyFile << arr[i].key;
        MyFile << "\n";
    }
    MyFile << arr[size-1].key;
    cout << "\nOutput path: " + output_path << endl;
    MyFile.close();
}
