#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cassert>


using std::string;
using std::vector; 
using std::cout; 
using std::endl; 
using std::ifstream; 
using std::ios; 

class card
{
public:
	card(void); 
	card(int value, char suit, string image); 
	card(card& copy); 

	int getValue(void); 
	char getSuit(void);  
	string getImage(void); 

	void setValue(int value); 
	void setSuit(char suit); 
	void setImage(string image); 


	void print(void); 

	

private:
	int value; 
	char suit; 
	string image;      
	
};
