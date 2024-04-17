#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std; 

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

card::card()
{
	this->value = 0; 
	this->suit = '\0'; 
	this->image = "\0"; 
}

card::card(int value, char suit, string image)
{
	this->value = value; 
	this->suit = suit; 
	this->image = image;    
}

card::card(card& copy)
{
	this->value = copy.value; 
	this->suit = copy.suit; 
	this->image = copy.image;     
}

int card::getValue()
{
	return value; 
}

char card::getSuit()
{
	return suit; 
}

string card::getImage()
{
	return image; 
}

void card::setValue(int value)
{
	this->value = value; 
}

void card::setSuit(char suit)
{
	this->suit = suit; 
}

void card::setImage(string image)
{
	this->image = image;   
} 

void card::print()
{
	cout << "Value: " << value << ", Suit: " << suit << endl;    
}
