//Written By: Wafik Aboualim
//11/6/2022
#include "keyValuePair.h"
/*
------------------------------------------------------------------*
 Description: default constructor of keyValuePair that contains a key and a corrosponding dummy value = key*10 (dummy value)
 Pre: None
 Post: An empty object of keyValuePair is created with key = 0 and value = 0
 -----------------------------------------------------------------*
*/
keyValuePair::keyValuePair() {
	this->key = 0;
	this->value = 0;
}
/*
------------------------------------------------------------------*
 Description: constructor of keyValuePair that contains a key and a corrosponding dummy value = key*10 (dummy value)
 Pre: None
 Post: An object of keyValuePair is created with a key and a corrosponding value = 10*key
 -----------------------------------------------------------------*
*/
keyValuePair::keyValuePair(int key) {
	this->key = key;
	this->value = key * 10;
}
/*
------------------------------------------------------------------*
 Description: Setter of object keyValuePair that take an integer key as an argument.
 Pre: An instance of keyValuePair
 Post: The instance object keyValuePair has the argument key and a value equal to key*10
 -----------------------------------------------------------------*
*/
void keyValuePair::setValue(int key)
{
	this->key = key;
	this->value = key * 10;
}
