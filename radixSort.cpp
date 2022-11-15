//Written By: Wafik Aboualim
//Main Project, Section C
//CS-312 Introduction to Algorithms
//11/6/2022
#include "radixSort.h"
/*
------------------------------------------------------------------*
 Description: Default constructor of radixSort
 initialize sizeArr = 0
 Pre: None
 Post: An empty instance of radixSort
 -----------------------------------------------------------------*
*/
radixSort::radixSort() {
    this->sizeArr = 0;
}
/*
------------------------------------------------------------------*
 Description: constructor of radixSort
 set the sizeArr to an integer given as an argument
 Pre: An array of type of keyValuePair with size equal to the size given in the argument
 Post: An instance of object radixSort
 -----------------------------------------------------------------*
*/
radixSort::radixSort(int sizeArr) {
    this->sizeArr = sizeArr;
}
/*
------------------------------------------------------------------*
 Description: A sub-routine that finds the object with the max key in an array of type keyValuePair
return an integer of the max key in the array of keyValuePair
 Pre: an instance of radixSort, and an array of type keyValuePair
 Post: An integer that corrosponds to the max key in the array of keyValuePair
 -----------------------------------------------------------------*
*/
int radixSort::getMax(keyValuePair pairArr[])
{
    int mx = pairArr[0].key;
    for (int i = 1; i < sizeArr; i++)
        if (pairArr[i].key > mx)
            mx = pairArr[i].key;
    return mx;
}
/*
------------------------------------------------------------------*
 Description: A sub-routine of counting sort
 sort the array of type keyValuePair by the digit in position exp of their keys 
 Pre: An instance of radixSort and an array of type keyValuePair
 Post: An array sorted based on the digit in position exp
 -----------------------------------------------------------------*
*/
void radixSort::countSort(keyValuePair pairArr[], int exp)
{
    int* output = new int[sizeArr]; // output array
    int i, count[10] = { 0 };

    // Store count of occurrences in count[]
    for (i = 0; i < sizeArr; i++) {
        count[(pairArr[i].key / exp) % 10]++;
    }
    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    // Build the output array
    for (i = sizeArr - 1; i >= 0; i--) {
        output[count[(pairArr[i].key / exp) % 10] - 1] = pairArr[i].key;
        count[(pairArr[i].key / exp) % 10]--;
    }
    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < sizeArr; i++) {
        //printf("%d || %d \n", pairArr[i].key, output[i]);
        pairArr[i] = keyValuePair(output[i]);
    }
    delete[] output;
}
/*
------------------------------------------------------------------*
 Description: Radix sort an array of type keyValuePair 
 Pre: an instance of radixSort, and an array of type keyValuePair
 Post: A keyValuePair array sorted based on the key field
 -----------------------------------------------------------------*
*/
void radixSort::radixsort(keyValuePair pairArr[])
{
    // Find the maximum number to know number of digits
    int m = getMax(pairArr);
    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(pairArr, exp);
}
